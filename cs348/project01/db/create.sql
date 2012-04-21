CREATE TABLE CourseEvaluations (
  EvaluationID integer NOT NULL,
  CourseID integer NULL REFERENCES Courses (CourseID),
  EvaluationName varchar(50) NULL,
  Type integer NULL,
  Weightage number(2,2) NULL,
  DeadlineDate date NULL,
  MeetingRoom varchar(50) NULL,
  PRIMARY KEY (EvaluationID)
);

CREATE TABLE Courses (
  CourseID integer NOT NULL,
  CourseName varchar(50) NULL,
  Semester varchar(50) NULL,
  Year integer NULL,
  Meets_At varchar(50) NULL,
  Room varchar(50) NULL,
  FacultyID integer NULL REFERENCES Faculties (FacultyID),
  PRIMARY KEY (CourseID)
);

CREATE TABLE CourseStudents (
  CourseID integer NOT NULL REFERENCES Courses (CourseID),
  StudentID integer NOT NULL REFERENCES Students (StudentID),
  PRIMARY KEY (CourseID,StudentID)
);

CREATE TABLE Departments (
  DepartmentID integer NOT NULL,
  Name varchar(50) NULL,
  HeadName varchar(50) NULL,
  PRIMARY KEY (DepartmentID)
);

CREATE TABLE EvaluationGrades (
  EvaluationID integer NOT NULL REFERENCES CourseEvaluations (EvaluationID),
  StudentID integer NOT NULL REFERENCES Students (StudentID),
  Grade number(5,2) NULL,
  PRIMARY KEY (EvaluationID,StudentID)
);

CREATE TABLE Faculties (
  FacultyID integer NOT NULL,
  DepartmentID integer NULL REFERENCES Departments (DepartmentID),
  Name varchar(50) NULL,
  PRIMARY KEY (FacultyID)
);

CREATE TABLE Students (
  StudentID integer NOT NULL,
  Name varchar(50) NULL,
  PRIMARY KEY (StudentID)
);
