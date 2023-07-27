/*
 * Arthur's Round Table
 * Author: Fred Pickel
 * ICPC GNYR 2020 Regional Contest
 *
 * I think this is hard
 * there are two solutions
 * one uses inversion in a cricle which takes a llot of formula fiddling
 * one just computes it numerically 
 * 	guess a radius find all the circles numercally, adjust radius
 * both of these took me a while to get all the bugs out
 */
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#define MAX_CIRCS	40
#define EPS (1.0e-8)
#define BIG	(1.0e40)
#define MA_PI	(3.14159265359)
//#define FORMAT_1	"%0.8lf\n"
//#define FORMAT_3	"%0.8lf %0.8lf %0.8lf\n"
#define FORMAT_1	"%0.3lf\n"
#define FORMAT_3	"%0.3lf %0.3lf %0.3lf\n"

//#define TEST
typedef struct _dpoint_
{
	double dpx;
	double dpy;
} DPOINT, *PDPOINT;

typedef struct _dcirc_ 
{
	double dcx;
	double dcy;
	double drad;
} DCIRC, *PDCIRC;

DCIRC outCirc, inCirc, invCirc, circs[MAX_CIRCS+1];
DCIRC baseOutCirc, baseInCirc, baseCircs[MAX_CIRCS+1];
double circrad, dScale;
DPOINT offPt;
/*
 * this method uses inversion in a circle to map
 * concentric circles with circles between tocircles where the inner
 * center is offset from the outer center
 * a point (x,y) inverted with respect to a circle with center x0,y0 and
 * radius r goes to (x',y') where (x',y') is on the same ray from (x0,y0)
 * as (x,y) and dist((x,y),(x0,y0))*dist((x',y'),(x0,y0)) = r^2
 */

DPOINT PointInvert(DPOINT invcen, double invrad, DPOINT src)
{
	DPOINT res;
	double dx, dy, mag, rsq;
	rsq = invrad*invrad;
	dx = src.dpx - invcen.dpx;
	dy = src.dpy - invcen.dpy;
	mag = dx*dx + dy*dy;
	if(mag < EPS) {
		res.dpx = res.dpy = BIG;
	} else {
		mag = 1.0/mag;
		res.dpx = invcen.dpx + rsq*dx*mag;
		res.dpy = invcen.dpy + rsq*dy*mag;
	}
	return res;
}

/*
 * a circle (,y,r) inverted with respect to another (x0,y0,r0)
 * is another circle (x',y',r') where 
 * x' = x0 + s*(x-x0)
 * y' = y0 + s*(y - y0)
 * r' = fabs(s)*r
 * and s = r0^2/((x - x0)^2 + (y - y0)^2 - r^2)
 * (you can derive this by transforming (x--r,y) and (x+r,y)
 *	the average is the center and 1/2 the difference is the new radius)
 */
int CircleInvert(DCIRC invCirc, DCIRC srcCirc, PDCIRC pResCirc)
{
	double dx, dy, rsq, mag, s;
	rsq = invCirc.drad*invCirc.drad;
	dx = srcCirc.dcx - invCirc.dcx;
	dy = srcCirc.dcy - invCirc.dcy;
	mag = dx*dx + dy*dy - srcCirc.drad*srcCirc.drad;
	if(fabs(mag) < EPS) {
		return -1;
	}
	s = rsq/mag;
	pResCirc->dcx = invCirc.dcx + s*dx;
	pResCirc->dcy = invCirc.dcy + s*dy;
	pResCirc->drad = (srcCirc.drad*fabs(s));
	return 0;
}

/* Find the radius of the inner circle when theouter cicrle has radius 1
 * and the inner and outer circles are concentric
 * if r is radius of the circle between the inner and outer circle
 * then the angle between the line to a point of tangency og two such circles and
 * the line to the center of one of them is (2*PI)/(2*ncircs) and the distance o the center
 * is (1.0 - r) so
 * s = sin(PI/ncircs) = r/(1 - r) and r = s/(1 + s) and the inner circel has radius
 * 1 - 2*r
 */
double GetBaseRadRatio(int nCircs)
{
	double s = sin(MA_PI/((double)nCircs));
	circrad = s/(1.0 + s);
	return (1.0 - 2.0*circrad);
}

/*
 * set up concentric circles (cntered at (0,0) with nCircs circles between tangent to both
 * and to their neighbors Outer circle radius 1
 * note: since inversion (reflection) in the circle reverses orientation
 ( we start the base circles on the left and go clockwise
 */
int SetBaseCircs(int nCircs)
{
	double ang, dang, ptrad;
	int i;
	baseOutCirc.dcx = baseOutCirc.dcy = 0.0;
	baseOutCirc.drad = 1.0;
	baseInCirc.dcx = baseInCirc.dcy = 0.0;
	baseInCirc.drad = GetBaseRadRatio(nCircs);
	ptrad = baseInCirc.drad + circrad;
	dang = 2.0*MA_PI/((double)nCircs);
	for(i = 0, ang = MA_PI; i < nCircs ; i++, ang -= dang) {
		baseCircs[i].dcx = ptrad*cos(ang);
		baseCircs[i].dcy = ptrad*sin(ang);
		baseCircs[i].drad = circrad;
	}
	return 0;
}

/*
 * transform inCirc using invCirc the offset by offPt and scale by dScale
 */
int TransCirc(DCIRC inCirc, PDCIRC pOutCirc)
{
	int ret;
	if((ret = CircleInvert(invCirc, inCirc, pOutCirc)) != 0) {
		return ret;
	}
	pOutCirc->dcx = (pOutCirc->dcx - offPt.dpx)*dScale;
	pOutCirc->dcy = (pOutCirc->dcy - offPt.dpy)*dScale;
	pOutCirc->drad *= dScale;
	return 0;
}

/*
 * find a circle which inverts the concentric circles to circle where the
 * inner circle cnter is new_offset from the outer cicle center and
 * the new_offset/outer_circle_radius = offset/outRad
 * then set offset to outer circle center and scale to outRad/outer_circle_radius
 * s_in = R^2/(x0^2 - r_in^2)		s_out = R^2/(x0^2 - 1)
 * x_in' = x0 + s_in*(-x0)			x_out' = x0 + s_out * (-x0)
 * new_offset = x_in' - x_out' = (s_in - s_out)*(-x0) = (-x0)*R^2*(r_in^2 - 1)/((x0^2 - r_in^2)*(x0^2 - 1))
 * outer_circle_radius = fabs(s_out)
 * new_offset/outer_circle_radius = 
 * (-x0)*R^2*(r_in^2 - 1)/((x0^2 - r_in^2)*(x0^2 - 1)) * ((x0^2 - 1)/R^2)
 * = (-x0)*(r_in^2 - 1)/(x0^2 - r_in^2) = offset/outRad = rat
 * so rat*x0^2 - rat*r_in^2 = -x0*(r_in^2 - 1)
 * rat *x0^2 + x0*(r_in^2 - 1) - rat*r_in^2 = 0
 * use quadratic eqn
 * pick R big enough to include concentric circles
 */
int CompInvCirc( double outRad, double offset)
{
	double rat, rsq, a, b, c, x, tst;
	DCIRC out, in;
	rat = offset;
	if(fabs(rat) < EPS) {
		return -1;
	}
	rat = rat/outRad;
	a = rat;
	rsq = baseInCirc.drad*baseInCirc.drad;
	b = rsq - 1.0;
	c = -(rsq*rat);
	invCirc.dcy = 0.0;
	invCirc.dcx = x = (-b + sqrt(b*b - 4.0*a*c))/(2.0*a);
	/* check center not on either circle */
	if((fabs(x - 1.0) < EPS) || (fabs(x + 1.0) < EPS) ||
		(fabs(x - (outCirc.dcx + outCirc.drad)) < EPS) ||
		(fabs(x + (outCirc.dcx + outCirc.drad)) < EPS)) {
		return -2;
	}
	invCirc.drad = 2.0*fabs(x);
	CircleInvert(invCirc, baseOutCirc, &out);
	CircleInvert(invCirc, baseInCirc, &in);
	tst = in.dcx - out.dcx;
	if(fabs(tst) < EPS) {
		return -3;
	}
	tst = tst/out.drad;
	if((fabs(tst - rat) > EPS) && (fabs(tst + rat) > EPS)) {
		return -4;
	}
	offPt.dpx = out.dcx;
	offPt.dpy = out.dcy;
	dScale = outRad/out.drad;
	return 0;

}

int FindOffsetCircs(double outrad, int nCircs, double offset)
{
	int i, ret;
	SetBaseCircs(nCircs);
	if(fabs(offset) < EPS) {
		outCirc.dcx = outCirc.dcy = 0.0;
		outCirc.drad = outrad;
		inCirc.dcx = inCirc.dcy = 0.0;
		inCirc.drad = outrad*baseInCirc.drad;
		for(i = 0; i < nCircs ; i++) {
			/* flip x to counteract flip in making base circles */
			circs[i].dcx = -baseCircs[i].dcx*outrad;
			circs[i].dcy = baseCircs[i].dcy*outrad;
			circs[i].drad = baseCircs[i].drad*outrad;
		}
	} else {
		if((ret = CompInvCirc(outrad, offset)) == 0) {
			TransCirc(baseOutCirc, &outCirc);
			TransCirc(baseInCirc, &inCirc);
			for(i = 0; i < nCircs ; i++) {
				TransCirc(baseCircs[i], &circs[i]);
			}
		} else {
			return ret;
		}
	}
	return 0;
}

char inbuf[256];

int main()
{
	int nCirc, ret;
	double outrad, offset, diam, inrad, tst;
#ifdef TEST
	int p, sz, prob;
	p = 0;
	while(1) {
		p++;
		printf("%d:\n", p);
	if(fgets(&(inbuf[0]), 255, stdin) == NULL) {
		fprintf(stderr, "read failed on prob header\n");
		return -1;
	}
	if(sscanf(&(inbuf[0]), "%d %d", &prob, &sz) != 2){
		fprintf(stderr, "scan failed on problem header\n");
		return -2;
	}
	if(p != prob) {
		fprintf(stderr, "prob label %d != expected %d\n", prob, p);
		return -2;
	}

#endif
	if(fgets(&(inbuf[0]), 255, stdin) == NULL) {
		fprintf(stderr, "read failed on input data\n");
		return -3;
	}
	if(sscanf(&(inbuf[0]), "%lf %d %lf", &diam, &nCirc, &offset) != 3){
		fprintf(stderr, "scan failed on problem data\n");
		return -4;
	}
	outrad = 0.5*diam;
	inrad = outrad * GetBaseRadRatio(nCirc);
	tst = outrad*circrad;
	if((diam < 8.0) || (diam > 30.0)) {
		fprintf(stderr, "table diameter %lf not in range 8 ... 30\n", outrad);
		return -5;
	}
	if((nCirc < 7) ||(nCirc > MAX_CIRCS)) {
		fprintf(stderr, "num knights %d not in range 6 ... %d\n", nCirc, MAX_CIRCS);
		return -6;
	}
	if(offset > (tst)) {
		fprintf(stderr, "offset %lf > original trencher radius %lf\n",
			offset, tst);
		return -7;
	}
	if((ret = FindOffsetCircs(outrad, nCirc, -offset)) != 0) {
		return ret;
	}
	printf(FORMAT_1, inCirc.drad);
	printf(FORMAT_3, circs[0].dcx, circs[0].dcy, circs[0].drad);
	printf(FORMAT_3, circs[1].dcx, circs[1].dcy, circs[1].drad);
	printf(FORMAT_3, circs[2].dcx, circs[2].dcy, circs[2].drad);
	printf(FORMAT_3, circs[3].dcx, circs[3].dcy, circs[3].drad);
#ifdef TEST
	}
#endif
	return 0;
}
