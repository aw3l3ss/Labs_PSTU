#include <iostream>

typedef struct Test {
    std::string test1;
    std::string test2;
} Test;

int main() {
    FILE *fp = fopen("test.bin", "w");

    Test t1;
    t1.test1 = "test1";
    t1.test2 = "test2";
    fwrite(&t1, sizeof(Test), 1, fp);

    Test t2;
    t2.test1 = "test33";
    t2.test2 = "test44";
    fwrite(&t2, sizeof(Test), 1, fp);

    fclose(fp);

    fp = fopen("test.bin", "r");
    Test t3;
    fread(&t3, sizeof(Test), 1, fp);
    Test t4;
    fread(&t4, sizeof(Test), 1, fp);
    fclose(fp);

    std::cout << t3.test1 << std::endl;
    std::cout << t3.test2 << std::endl;
    std::cout << t4.test1 << std::endl;
    std::cout << t4.test2 << std::endl;

    return 0;
}