CREATE TABLE CourseEvaluations (
  EvaluationID int(10) NOT NULL AUTO_INCREMENT,
  CourseID int(10) DEFAULT NULL,
  EvaluationName varchar(50) DEFAULT NULL,
  Type int(10) DEFAULT NULL,
  Weightage decimal(2,2) DEFAULT NULL,
  DeadlineDate datetime DEFAULT NULL,
  MeetingRoom varchar(50) DEFAULT NULL,
  PRIMARY KEY (EvaluationID),
  KEY FK_CourseEvaluations_CourseID (CourseID),
  CONSTRAINT FK_CourseEvaluations_CourseID FOREIGN KEY (CourseID) REFERENCES Courses (CourseID)
);

CREATE TABLE Courses (
  CourseID int(10) NOT NULL AUTO_INCREMENT,
  CourseName varchar(50) DEFAULT NULL,
  Semester varchar(50) DEFAULT NULL,
  Year int(11) DEFAULT NULL,
  Meets_At varchar(50) DEFAULT NULL,
  Room varchar(50) DEFAULT NULL,
  FacultyID int(11) DEFAULT NULL,
  PRIMARY KEY (CourseID),
  KEY FK_Courses_FacultyID (FacultyID),
  CONSTRAINT FK_Courses_FacultyID FOREIGN KEY (FacultyID) REFERENCES Faculties (FacultyID)
);

CREATE TABLE CourseStudents (
  CourseID int(10) NOT NULL DEFAULT '0',
  StudentID int(10) NOT NULL DEFAULT '0',
  PRIMARY KEY (CourseID,StudentID),
  KEY FK_CourseStudents_StudentID (StudentID),
  CONSTRAINT FK_CourseStudents_CourseID FOREIGN KEY (CourseID) REFERENCES Courses (CourseID),
  CONSTRAINT FK_CourseStudents_StudentID FOREIGN KEY (StudentID) REFERENCES Students (StudentID)
);

CREATE TABLE Departments (
  DepartmentID int(10) NOT NULL AUTO_INCREMENT,
  Name varchar(50) DEFAULT NULL,
  HeadName varchar(50) DEFAULT NULL,
  PRIMARY KEY (DepartmentID)
);

CREATE TABLE EvaluationGrades (
  EvaluationID int(10) NOT NULL DEFAULT '0',
  StudentID int(10) NOT NULL DEFAULT '0',
  Grade decimal(5,2) DEFAULT NULL,
  PRIMARY KEY (EvaluationID,StudentID),
  KEY FK_EvaluationGrades_StudentID (StudentID),
  CONSTRAINT FK_EvaluationGrades_EvaluationID FOREIGN KEY (EvaluationID) REFERENCES CourseEvaluations (EvaluationID),
  CONSTRAINT FK_EvaluationGrades_StudentID FOREIGN KEY (StudentID) REFERENCES Students (StudentID)
);

CREATE TABLE Faculties (
  FacultyID int(10) NOT NULL AUTO_INCREMENT,
  DepartmentID int(10) DEFAULT NULL,
  Name varchar(50) DEFAULT NULL,
  PRIMARY KEY (FacultyID),
  KEY FK_Faculties_DepartmentID (DepartmentID),
  CONSTRAINT FK_Faculties_DepartmentID FOREIGN KEY (DepartmentID) REFERENCES Departments (DepartmentID)
);

CREATE TABLE Students (
  StudentID int(10) NOT NULL AUTO_INCREMENT,
  Name varchar(50) DEFAULT NULL,
  PRIMARY KEY (StudentID)
);
