Defination:
Structure is a user define datatype which is used to store dis-similar types of values.

Note:
The size of structure is equals to sum of all structure member size.

Program:
struct student{
    int rollno;
    float marks;
};
int main()
{
    struct student s1;
    s1.rollno=54;
    s1.marks=9.5;
    cout<<"Roll no :"<<s1.rollno<<"\n";
    cout<<"Name:"<<s1.marks<<"\n";
    return 0;
}


