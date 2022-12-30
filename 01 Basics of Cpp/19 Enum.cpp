Defination:
Enumeration is a user define name that consist of integral constant.

Example:
month-> {jan,feb,mar,...,dec}
week-> {sun,mon,...,sat}

Syntax:
enum values{value1, value2, ..., valueN}

int main()
{
    enum gender{
        male,female,others
    };
    cout<<male<<"\n";
    gender str=others;
    cout<<str;
    return 0;
}


