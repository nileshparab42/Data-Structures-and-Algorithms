Defination:
Union is a user define datatype which is used to store dis-similar types of values.

Note:
The size of union is equal to its biggest member.
At a time it accepts value only one member.

union teacher{
    int tid;
    char tname[10];
};
int main()
{
    struct student s1;
    union teacher t1;
    cout<<"Union size :"<<sizeof(t1)<<"\n";
    return 0;
}