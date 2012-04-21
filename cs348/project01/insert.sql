INSERT INTO CourseEvaluations (EvaluationID, CourseID, EvaluationName, Type, Weightage, DeadlineDate, MeetingRoom) VALUES
	(1, 1, 'Homework 1', 0, 0.10, '15-MAR-12', 'HAAS G066'),
	(2, 1, 'Homework 2', 0, 0.10, '15-APR-12', 'HAAS G066'),
	(3, 1, 'Midterm', 1, 0.30, '20-APR-12', 'ELLT 116'),
	(4, 1, 'Final Project', 3, 0.30, '27-APR-12', 'LWSN 1123'),
	(5, 1, 'Final Exam', 2, 0.30, '02-MAY-12', 'ELLT 116'),
	(6, 1, 'Homework 3', 0, 0.10, '15-MAY-12', 'HAAS G066');

INSERT INTO Courses (CourseID, CourseName, Semester, Year, Meets_At, Room, FacultyID) VALUES
	(1, 'Information Systems', 'Spring', 2012, '8:30 AM', 'HAAS G066', 1),
	(2, 'Operating Systems', 'Spring', 2012, '12:00 PM', 'EE 117', 3),
	(3, 'Software Engineering', 'Spring', 2012, '11:30 AM', 'WTHR 104', 1);

INSERT INTO CourseStudents (CourseID, StudentID) VALUES
	(1, 1),
	(2, 1),
	(3, 1),
	(1, 3);

INSERT INTO Departments (DepartmentID, Name, HeadName) VALUES
	(1, 'Computer Science', 'Bill Gates'),
	(2, 'Mathematics', 'Albert Einstein'),
	(3, 'Physics', 'Bejamin Franklin'),
	(4, 'Liberal Arts', 'Hillory Clinton');

INSERT INTO EvaluationGrades (EvaluationID, StudentID, Grade) VALUES
	(1, 1, 100.00),
	(2, 1, 80.00),
	(5, 3, 100.00);

INSERT INTO Faculties (FacultyID, DepartmentID, Name) VALUES
	(1, 1, 'Elisa Bertino'),
	(2, 1, 'Buster Dunsmore'),
	(3, 1, 'Dongyan Xu'),
	(4, 4, 'Thomas Brown');

INSERT INTO Students (StudentID, Name) VALUES
	(1, 'Matt McCormick'),
	(3, 'Elizabeth Puccinelli'),
	(4, 'Joe Martella'),
	(5, 'Kyle Rector');
