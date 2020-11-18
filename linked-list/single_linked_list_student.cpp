#include <iostream>
using namespace std;

struct Student
{
       string name;
       string candidateNumber;
       float oneSubjectScore;
       float twoSubjectScore;
       bool english;
       Student *student;
};

typedef struct Student STUDENT;

struct ListStudent
{
       STUDENT *pHEAD;
       STUDENT *pTAIL;
};

typedef struct ListStudent LISTSTUDENT;

void init(LISTSTUDENT &S)
{
       S.pHEAD = S.pTAIL = NULL;
}

STUDENT *createStudent(
    STUDENT *&student,
    string name,
    string candidateNumber,
    float oneSubjectScore,
    float twoSubjectScore,
    bool english)
{
       if (student != NULL)
       {
              student->name = name;
              student->candidateNumber = candidateNumber;
              student->oneSubjectScore = oneSubjectScore;
              student->twoSubjectScore = twoSubjectScore;
              student->english = english;
              student->student = NULL;
       }
       return student;
}

void addStudent(LISTSTUDENT &ls, STUDENT *s)
{
       if (ls.pHEAD == NULL && ls.pTAIL == NULL)
       {
              ls.pHEAD = s;
              ls.pTAIL = s;
       }
       else
       {
              ls.pTAIL->student = s;
              ls.pTAIL = s;
       }
}

void inputListStudent(LISTSTUDENT &ls, int n)
{
       init(ls);
       for (int i = 0; i < n; i++)
       {
              STUDENT *S = new STUDENT;
              string name = "A1";
              string candidateNumber = "101";
              float oneSubjectScore = 5;
              float twoSubjectScore = 6;
              bool isEnglish = 1;
              // fflush(stdin);
              // cout << "\nStudent " << i << " :" << endl;
              // cout << "===> Name: ";
              // cin >> name;
              // fflush(stdin);
              // cout << "\n===> Candidate Number: ";
              // cin >> candidateNumber;
              // fflush(stdin);
              // cout << "\n===> One Subject Score: ";
              // cin >> oneSubjectScore;
              // fflush(stdin);
              // cout << "\n===> Two Subject Score: ";
              // cin >> twoSubjectScore;
              // cout << "\n===> English: ";
              // cin >> isEnglish;
              createStudent(S, name, candidateNumber, oneSubjectScore, twoSubjectScore, isEnglish);
              addStudent(ls, S);
       }
}

void outListStudent(LISTSTUDENT ls)
{
       if (ls.pHEAD == NULL && ls.pTAIL == NULL)
       {
              cout << "LIST STUDENT IS EMPTY";
       }
       else
       {
              STUDENT *s = ls.pHEAD;
              while (s != NULL)
              {
                     cout << "\nName: " << s->name;
                     cout << "\nCandidate Number: " << s->candidateNumber;
                     cout << "\nOne Subject Score: " << s->oneSubjectScore;
                     cout << "\nTwo Subject Score: " << s->twoSubjectScore;
                     cout << "\nEnglish: " << s->english;
                     cout << "\n==================";
                     s = s->student;
              }
       }
}

int countStudentsPassesExam(STUDENT *pHEAD, float standardScore)
{
       int count = 0;
       for (STUDENT *p = pHEAD; p != NULL; p = p->student)
       {
              if (p->oneSubjectScore >= standardScore && p->twoSubjectScore >= standardScore && p->english == true)
              {
                     count++;
              }
       }
       return count;
}

float findStandardScore(STUDENT *pHEAD, int target)
{
       int count[20] = {0};
       for (STUDENT *p = pHEAD; p != NULL; p = p->student)
       {
              if (p->oneSubjectScore >= 5 && p->twoSubjectScore >= 5 && p->english == true)
              {
                     float totalScore = p->oneSubjectScore + p->twoSubjectScore;
                     int index = (totalScore - 10) * 2;
                     count[index]++;
              }
       }

       int i = 19;
       while (target >= 0 && i > 0)
       {
              target = target - count[i];
              i--;
       }
       return ((1.0 * (i)) / 2) + 11;
}

int main()
{
       LISTSTUDENT LS;
       int n = 5;
       inputListStudent(LS, n);
       outListStudent(LS);
       cout << "The quantity of Student passes exam: " << countStudentsPassesExam(LS.pHEAD, 5);
       cout << "\nStandard Score: " << findStandardScore(LS.pHEAD, 20);
       return 0;
}