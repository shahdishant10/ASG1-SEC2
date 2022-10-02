#include"header.cpp"

int main()
{
    ifstream filein;              //reads the file
    ofstream fileout;             //to store the output
    string line,word,fname,lname,mname;     //Variable declaration of datatype string
    string G;                     //Variable declaration of datatype string
    int cnt,value;                //Variable declaration of interger datatype


filein.open("grades_Section2.txt");      //reads the grades_Secrion2.txt file
fileout.open("Result.txt");              //result is stored in Result.txt file
    if(!filein.is_open())                //Loop is fail fails to open
    {
        cout<<"File Cant be Opened \n";
    return -1;
    }
   filein>>studentno >> examno;

    int** marks = new int* [studentno];    //Declaration of Dynamic array of 2 dimension
    for (int i = 0; i < studentno; i++)    //Loop for storing the marks
    {
        marks[i] = new int[examno];
    }
   int* Avg=new int[examno];               //Declaration of Dynamic array of 1 dimension to store the average
   char** grade = new char* [studentno];   //Declaration of Dynamic array of 2 dimension
    for (int i = 0; i < studentno; i++)    //Loop for storing grade of students
    {
        grade[i] = new char[examno];
    }
   struct studentdata
   {
       string firstname;
       string lastname;
       string middlename;
   };
   studentdata *s=new studentdata[studentno];
   getline(filein, line);                         //Reads till the end of the file i.e. till the last line
   int i=0;
   while(getline(filein, line)&&(i<studentno))
    {
        istringstream in(line);
        in>>fname>>lname>>mname;

       if(isNumber(mname))
       {
           cnt=stoi(mname);                      //converts string to integers
           mname=" ";
       }

for(int j=0;j<examno;j++)
{
    in>>value;
    marks[i][j]=value;
}

        s[i].firstname = fname;
        s[i].lastname = lname;
        s[i].middlename = mname;
        i++;

}
        Average(marks,examno,studentno,Avg);
        Getgrade(marks,Avg,examno,studentno,grade);
            for (int a = 0; a < studentno; a++)
    {
        cout << "Student Name:- " << s[a].firstname<<" "<<s[a].lastname<<" "<<s[a].middlename << endl;
        cout << "The Exam Marks are:- " << endl;
        for (int b = 0; b < examno; b++)
        {
            cout << " " << right << setw(25)<< "Exam" << b + 1 << "  :-";
            cout << "  " << marks[a][b] << right << setw(15);
            cout << "Grade:- " << grade[a][b] << endl;
        }
        cout << endl;
    }
     for (int a= 0; a < studentno; a++)
    {
        fileout << "Student Name:- " << s[a].firstname<<" "<<s[a].lastname<<" "<<s[a].middlename << endl;
        fileout << "The Exam Marks are:- " << endl;
        for (int b = 0; b < examno; b++)
        {
            fileout << " " << right << setw(25) << "Exam" << b + 1 << "  :-";
            fileout << "  " << marks[a][b] << right << setw(15);
            fileout << "Grade:- " << grade[a][b] << endl;
        }
        fileout << endl;
    }
filein.close();
fileout.close();

return 0;


    }




