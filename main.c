#include <stdio.h>

// 数据结构声明
    
// 单条开销
typedef struct singleCost {
    double money;  // 金额
    char use[50];  // 用途
}COST;

// 每日开销
typedef struct dayExpense {
    char date[20];  // yyyy-mm-dd
    COST date_cost[50];  // 预设50条开销记录，
}EXPENSE;

// 函数声明
void showMain();            // 主界面函数
void addCost(char date[20], double money, char use[50]);
void checkCost(char date[20], int type);

// 变量声明


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
                    scanf("%s", use);
                    
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

void readFile(FILE* fp) {

}


void addCost(char date[20], double money, char use[50]) {

}

void checkCost(char date[20], int type) {

}
