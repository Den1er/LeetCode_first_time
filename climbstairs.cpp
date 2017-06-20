public:
    uint result;
    void climb(int level)
{
    if(level==0)    ++result;
    if(level==-1)   break;
    climb(level-1);
    climb(level-2);
}
