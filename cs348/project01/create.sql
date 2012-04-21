DROP TABLE CourseEvaluations CASCADE CONSTRAINTS;
CREATE TABLE CourseEvaluations (
  EvaluationID integer NOT NULL,
  CourseID integer DEFAULT NULL REFERENCES Courses (CourseID),
  EvaluationName varchar(50) DEFAULT NULL,
  Type integer DEFAULT NULL,
  Weightage number(2,2) DEFAULT NULL,
  DeadlineDate datetime DEFAULT NULL,
  MeetingRoom varchar(50) DEFAULT NULL,
  PRIMARY KEY (EvaluationID)
);

DROP TABLE Courses CASCADE CONSTRAINTS;
CREATE TABLE Courses (
  CourseID integer NOT NULL,
  CourseName varchar(50) DEFAULT NULL,
  Semester varchar(50) DEFAULT NULL,
  Year integer DEFAULT NULL,
  Meets_At varchar(50) DEFAULT NULL,
  Room varchar(50) DEFAULT NULL,
  FacultyID integer DEFAULT NULL REFERENCES Faculties (FacultyID),
  PRIMARY KEY (CourseID)
);

DROP TABLE CourseStudents CASCADE CONSTRAINTS;
CREATE TABLE CourseStudents (
  CourseID integer NOT NULL DEFAULT '0' REFERENCES Courses (CourseID),
  StudentID integer NOT NULL DEFAULT '0' REFERENCES Students (StudentID),
  PRIMARY KEY (CourseID,StudentID)
);

DROP TABLE Departments CASCADE CONSTRAINTS;
CREATE TABLE Departments (
  DepartmentID integer NOT NULL,
  Name varchar(50) DEFAULT NULL,
  HeadName varchar(50) DEFAULT NULL,
  PRIMARY KEY (DepartmentID)
);

DROP TABLE EvaluationGrades CASCADE CONSTRAINTS;
CREATE TABLE EvaluationGrades (
  EvaluationID integer NOT NULL DEFAULT '0' REFERENCES CourseEvaluations (EvaluationID),
  StudentID integer NOT NULL DEFAULT '0' REFERENCES Students (StudentID),
  Grade number(5,2) DEFAULT NULL,
  PRIMARY KEY (EvaluationID,StudentID)
);

DROP TABLE Faculties CASCADE CONSTRAINTS;
CREATE TABLE Faculties (
  FacultyID integer NOT NULL,
  DepartmentID integer DEFAULT NULL REFERENCES Departments (DepartmentID),
  Name varchar(50) DEFAULT NULL,
  PRIMARY KEY (FacultyID)
);

DROP TABLE Students CASCADE CONSTRAINTS;
CREATE TABLE Students (
  StudentID integer NOT NULL,
  Name varchar(50) DEFAULT NULL,
  PRIMARY KEY (StudentID)
);
