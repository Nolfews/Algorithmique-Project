int main()
{
    char *str = "test";
    for (int i = 0; i <= 10; i++) {
        str[i] = 't';
        write(1, "test", 5);
    }
}