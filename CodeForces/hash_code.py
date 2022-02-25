from __future__ import annotations

import pathlib

from hungarian_algorithm import algorithm

class Person:
    def __init__(self, name: str):
        self.name = name
        self.skill = {}
        self.working = False
    
    def add_skill(self, skill_name, skill_level):
        self.skill[skill_name] = skill_level
    
    def is_free(self):
        return not self.working
    
    def __repr__(self) -> str:
        skills = []
        for skill, level in self.skill.items():
            skills.append(f"{skill}: {level}")
        skills = " | ".join(skills)
        return f"{self.name}, {skills}"
        # return f"{self.name}, {self.skill}"

class Project:
    def __init__(self, name: str, days: int, points: int, due: int):
        self.name = name
        self.days = days
        self.due = due
        self.points = points
        #string->int
        self.requirements = {}

    def add_requirement(self, name, skill):
        self.requirements[name] = skill
    def __repr__(self) -> str:
        return f"Name: {self.name}, Days: {self.days}, Due: {self.due}, Points: {self.points}\n{self.requirements}"
        
        
# Get a list of available members and list of remaining projects
# Output a list of possible projects

# a func to validate if the function can be
# If there's a skill that nobody has or a skill that requires a skill level higher than anyone has
def get_possible_projects(people_list : list[Person], projects_list : list[Project]):
    return [project for project in projects_list if is_project_possible(project, people_list)]

def is_project_possible(project : Project, people_list : list[Person]) -> bool:
    for skill, level in project.requirements.items():
        if not people_have_skills(people_list, skill, level):
            return False
        req = project.requirements
        G = {}
        for person in people_list:
            skill_map = {k:1 for k,v in person.skill.items() if k in req and v >= req[k] - 1}
            if len(skill_map) > 0:
                G[person.name] = skill_map
                # map (str -> map (str -> int))
        # or, if they can be mentored, return true...
        total = algorithm.find_matching(G, matching_type = 'max', return_type = 'total')
        print(total)
        print(G)
        print(req)
        if total == len(req):
            return True
        return False

def people_have_skills(people_list : list[Person], skill : str, required_level : int) -> bool:
    for person in people_list:
        if skill in person.skill and person.skill[skill] >= required_level:
            return True
    return False

def get_possible_people(persons_list):
    available_people = []
    for person in persons_list:
        if person.is_free():
            available_people.append(person)
    return available_people

# def get_people_skills(personp): #roject can be run
# # a func to loop through timestamps and run the validation functions_list):
#     # get all skills and levels
#     pass


def get_project_score(project, timestamp):
    return project.points - max((timestamp - project.due), 0)

def get_kth_best_project(projects_possible_list, k, timestamp): #timestamp = current day
    # sort by score, then by earliest (smallest) due date
    projects_possible_list.sort(key=lambda project: (get_project_score(project, timestamp), -project.due))
    return projects_possible_list[k]

    # projects = []
    # for project in projects_possible_list:
    #     projects.append((get_project_score(project, timestamp), project))
    # projects.sort(key=lambda x: (x[0], -x[1].due)) # sort by score, then by earliest (smallest) due date
    # return projects[k][1]

# maximize most contributors to increase in skill level
def get_best_contributors(project: Project, persons_list):
    contributors = []
    
    

    return contributors
    

def read_file(file_name : str) -> Tuple[list[Person], list[Project]]:
    with open(str(file_name), "r") as f:
        # for line in f:
        #     print(line)
        num_people = 0
        num_projects = 0
        line = f.readline()
        num_people, num_projects = [int(x) for x in line.strip().split(" ")]
        print(num_people, num_projects)

        # get people
        people = []
        for _ in range(num_people): 
            person = f.readline().strip().split(" ")
            person_name = person[0]
            person_num_skills = int(person[1])
            # get person skills
            new_person = Person(person_name)
            for _ in range(person_num_skills):
                skill = f.readline().strip().split(" ")
                skill_name = skill[0]
                skill_level = int(skill[1])
                new_person.add_skill(skill_name, skill_level)

            people.append(new_person)
            
        # get projects
        projects = []
        for _ in range(num_projects):
            project = f.readline().split(" ")
            project_name = project[0]
            project_days = int(project[1])
            project_due = int(project[2])
            project_points = int(project[3])
            project_required_skill_num = int(project[4])

            new_project = Project(project_name, project_days, project_due, project_points)
        
            # get project requirements
            for _ in range(project_required_skill_num):
                requirement = f.readline().strip().split(" ")
                requirement_name = requirement[0]
                requirement_skill = int(requirement[1])
                new_project.add_requirement(requirement_name, requirement_skill)
            
            projects.append(new_project)
        return (people, projects)


def main():
    for filename in pathlib.Path("input").iterdir():
        people, projects = read_file(filename)
        for person in people:
            print(person)
    
        possible_projects = get_possible_projects(people, projects)
        for project in possible_projects:
            print(project)

        break # do only 1 file for now

if __name__ == "__main__":
    main()

"""
3 3
Anna 1
C++ 2
Bob 2
CSS 5
Maria 1
Python 3
Logging 5 10 5 1
WebServer 7 10 7 2
HTML 3
C++ 2
WebChat 10 20 20 2
Python 3
HTML 3
"""
