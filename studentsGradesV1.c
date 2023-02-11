/* studentsGradesV1.c
Author: Drew
Date: 02/11/2023
CS150 Assignment: 5 students with 4 exams
Each exam has a weight based on: 10%, 20%, 30% and 40% in that order
Display all names with final grades and their respective letter grades
Display a report showing the highest and lowes final grades with corresponding
student.
Display the standard deviation for the final grades.
*/
#include <stdio.h>
#include<math.h>

#define STUDENTS  5
#define EXAMS  4

void setStudent(char names[][20])
{
    printf("Student Names Entry\n");
    for (int i = 0; i < STUDENTS; i++)
    {
        printf("Enter student name: ");
        scanf("%s", names[i]);
    }
    
}

void setExams(char names[][20], float grades[][EXAMS])
{
    printf("Grades Entry:\n");
    for (int i = 0; i < STUDENTS; i++)
    {
        printf("Student %s exams entry:\n", names[i]);
        for (int j = 0; j <EXAMS; j++)
        {
            printf("Enter score for exam %d: ", j+ 1);
            scanf("%f", &grades[i][j]);
        }
    }
}

void setFinalGrades(float grades[][EXAMS], float finalGRD[])
{
    float weights[] = {.1, .2, .3, .4};
    float accum = 0.0;
    for(int i = 0; i < STUDENTS; i++)
    {
        for(int j = 0; j < EXAMS; j++)
        {
            accum += grades[i][j] * weights[j];
        }
        finalGRD[i] = accum;
        accum = 0.0;
    }
}

void setLetterGrade(float finalGRD[], char ltrGRD[])
{
    for (int i = 0; i < STUDENTS; i++)
    {
        if (finalGRD[i] >= 90)
            ltrGRD[i] = 'A';
        else 
            if (finalGRD[i] >= 80)
                ltrGRD[i] = 'B';
            else
                if (finalGRD[i] >= 70)
                    ltrGRD[i] = 'C';
                else
                    if (finalGRD[i] >= 60)
                        ltrGRD[i] = 'D';
                    else
                        ltrGRD[i] = 'F';
        
        
    }
}

void displayData(char students[][20], float exams[][EXAMS], float finalGRD[], char ltrGRD[])
{
    printf("Student Data\n");
    printf("Student\tExam1\tExam2\tExam3\tExam4\t\tGrade\tLetter\n");
    for (int i = 0; i < STUDENTS; i++)
    {
        printf("%s\t", students[i]);
        for (int j = 0; j < EXAMS; j++)
            printf("%.1f\t", exams[i][j]);
        printf("\t%.1f\t%c\n", finalGRD[i], ltrGRD[i]);
    }

}

void displayLowHigh(char students[][20], float finalGRD[])
{
    float highest, lowest;
    highest = lowest = finalGRD[0];
    int indexH, indexL;
    for (int i = 1; i < STUDENTS; i++)
    {
        if (finalGRD[i] >= highest)
        {
            highest = finalGRD[i];
            indexH = i;
        }
        if (finalGRD[i] <= lowest)
        {
            lowest = finalGRD[i];
            indexL = i;
        }
    }
    printf("Lowest Grade\nName\tGrade\n");
    printf("%s\t%.1f\n", students[indexL], lowest);
    printf("\n");
    printf("Highest Grade\nName\tGrade\n");
    printf("%s\t%.1f\n", students[indexH], highest);

}


void displayStandardDev(float grades[])
{
    float mean, accum, stdDev;
    accum = 0.0;

    for (int i = 0; i < STUDENTS; i++)
        accum += grades[i];
    mean = accum/STUDENTS;

    accum = 0.0;
    for (int i = 0; i < STUDENTS; i++)
        accum += pow(grades[i] - mean, 2);
    stdDev = sqrt(accum/STUDENTS);

    printf("Mean: %.1f\nStandard Deviation: %.1f\n", mean, stdDev);
    

}


int main()
{
    //Needed data
    char students[STUDENTS][20];
    float exams[STUDENTS][EXAMS];
    float finalGrades[STUDENTS];
    char letterGrades[STUDENTS];

    printf("Welcome to the Grading System\n");
    setStudent(students);
    setExams(students, exams);
    printf("\n");
    setFinalGrades(exams, finalGrades);
    setLetterGrade(finalGrades, letterGrades);
    displayData(students, exams, finalGrades, letterGrades);
    printf("\n\n");
    displayLowHigh(students, finalGrades);
    printf("\n");
    displayStandardDev(finalGrades);

    return 0;
}