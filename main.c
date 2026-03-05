#include <stdio.h>
#include <string.h>

// 函数声明
void showMain();            // 主界面函数
void addCost(char date[20], double money, char use[50]);  // 增加开销记录
void checkCost(char date[20], int type);  // 查看开销

int main() {
    showMain();

    return 0;
}

void showMain() {    
    while(1) {
        int choose;

        printf("\n======What's up the guys, please choose the following.======\n1. 增加开销记录\n2. 查询开销\n3. 退出查询\n\n");
        scanf("%d", &choose);

        switch (choose) {
            case 1:
                while(1) {
                    char date[20];
                    double money;
                    char use[50];

                    printf("\n请输入日期:");
                    scanf("%s", date);  // 后续优化为fgets

                    printf("请输入您此项开销的金额:");
                    scanf("%lf", &money);

                    printf("请输入您此项开销的用途:");
                    scanf("%s", use);   // 后续优化为fgets
                    
                    // 将开销记录添加到文件中
                    addCost(date, money, use);
                    printf("\n");
                
                    char more;
                    printf("是否还有新的开销记录?(y/n):");
                    scanf(" %c", &more);  // %c前面加空格可以跳过空白字符
                    if(more == 'n')  break;
                }
                break;
                
            case 2: {
                int type;
                printf("\n请输入您要查询的方式:\n1.按月份查询\n2.按日期查询\n");
                scanf("%d", &type);

                char date[20];
                if(type == 1) {
                    printf("\n请输入您所要查询的月份:");
                    scanf("%s", date);
                    checkCost(date, type);

                } else {
                    printf("\n请输入您所要查询的日期:");
                    scanf("%s", date);
                    checkCost(date, type);
                }
                break;
            }

            case 3:
                printf("Say Goodbye");
                return;
        
            default:
                printf("输入无效,请重新输入:\n");
        }
    }

}

void addCost(char date[20], double money, char use[50]) {
    FILE* fp = fopen("data.csv", "a");
    if (fp == NULL) {
        printf("\n无法打开文件\n");
        return ;
    }

    fprintf(fp, "%s,%.2lf,%s\n",date,money,use);
    fclose(fp);
}

void checkCost(char date[20], int type) {
        FILE* fp = fopen("data.csv", "r");
        if (fp == NULL) {
            printf("\n无法打开文件\n");
            return ;
        }

        char line[200];
        
        // 跳过第一行
        if (fgets(line, sizeof(line), fp) == NULL) {
            fclose(fp);
            return ;
        }

        // 总金额
        double total = 0;

        // 逐行读取文件内容
        while (fgets(line, sizeof(line), fp) != NULL) {
            char rec_date[20];
            double rec_money;
            char rec_use[50];

            if (sscanf(line, "%19[^,],%lf,%49[^\n]", rec_date, &rec_money, rec_use) == 3) {
                //按月份查询
                if (type == 1) {
                    if (strncmp(rec_date, date, strlen(date)) == 0) total += rec_money;
                    else continue;
                }

                // 按特定日期查询
                else if (type == 2) {
                    if (strcmp(rec_date, date) == 0) total += rec_money;
                    else continue; 
                } 
                
                // 输入其他数字
                else {
                    printf("\n功能正在开发中...\n");
                    break;
                }
            }

        }

        // 关闭文件
        fclose(fp);

        if (type == 1) {
            printf("\n%s月的开销为:%.2lf\n",date, total);
        }
        else if (type == 2) {
            printf("\n%s日的开销为:%.2lf\n",date, total);
        }
}
