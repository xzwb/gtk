// 计算器

#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include <math.h>
#include <stdlib.h>

#define EMPTY 0
#define NOEMPTY 1
#define MORE 1
#define LESS 0

// 运算数栈
typedef struct {
    double num[1024];
    int top;
} Num;

// 操作符栈
typedef struct {
    char c[1024];
    int top;
} Char;

/* --------------------------------- */

Num lnum;
Char lchar;

// 求次方的函数
int power(int n) 
{
    int a = 1;
    if (n == 0) {
        return 1;
    }
    if (n > 0) {
        for (int i = 0; i < n; i++) {
             a *= 10;
        }
        return a;
    }
    if (n < 0) {
        n = n * (-1);
        for (int i = 0; i < n; i++) {
            a /= 10;
        }
        return a;
    }
}

// 判断栈不是为空
int Empty(int num) {
    if (num == -1) {
        return EMPTY;
    } else {
        return NOEMPTY;
    }
}

// 操作数入栈
void PopNum(Num *lnum, double num)
{
    lnum->num[++lnum->top] = num;
}

// 操作数出栈
void PushNum(Num *lnum, double  *num)
{
    *num = lnum->num[lnum->top--];
}

// 运算符入栈
void PopChar(Char *lchar, char x)
{
    lchar->c[++lchar->top] = x;
}

// 运算符出栈
void PushChar(Char *lchar, char *x)
{
    *x = lchar->c[lchar->top--];
}

// 比较运算符优先级
int Judge(char a, char b)
{
    switch(a) {
        case '+':
                if (b == '+' || b == '-') {
                    return MORE;
                } else {
                    return LESS;
                }
        case '-':
                if (b == '-' || b == '+') {
                    return MORE;
                } else {
                    return LESS;
                }
        case '*':
        case '/':
                return MORE;
        default:break;
    }
}

void Zero(GtkButton *button, gpointer arg)
{
    char temp[1024];
    GtkEntry *entry = (GtkEntry *)arg;
    const char *str = gtk_entry_get_text(entry);
    strcpy(temp, str);
    strcat(temp, "0");
    gtk_entry_set_text(entry, temp);
}

void One(GtkButton *button, gpointer arg)
{
    char temp[1024];
    GtkEntry *entry = (GtkEntry *)arg;
    const char *str = gtk_entry_get_text(entry);
    strcpy(temp, str);
    strcat(temp, "1");
    gtk_entry_set_text(entry, temp);
}

void Two(GtkButton *button, gpointer arg)
{
    char temp[1024];
    GtkEntry *entry = (GtkEntry *)arg;
    const char *str = gtk_entry_get_text(entry);
    strcpy(temp, str);
    strcat(temp, "2");
    gtk_entry_set_text(entry, temp);
}

void Three(GtkButton *button, gpointer arg)
{
    char temp[1024];
    GtkEntry *entry = (GtkEntry *)arg;
    const char *str = gtk_entry_get_text(entry);
    strcpy(temp, str);
    strcat(temp, "3");
    gtk_entry_set_text(entry, temp);
}

void Four(GtkButton *button, gpointer arg)
{
    char temp[1024];
    GtkEntry *entry = (GtkEntry *)arg;
    const char *str = gtk_entry_get_text(entry);
    strcpy(temp, str);
    strcat(temp, "4");
    gtk_entry_set_text(entry, temp);
}

void Five(GtkButton *button, gpointer arg)
{
    char temp[1024];
    GtkEntry *entry = (GtkEntry *)arg;
    const char *str = gtk_entry_get_text(entry);
    strcpy(temp, str);
    strcat(temp, "5");
    gtk_entry_set_text(entry, temp);
}

void Six(GtkButton *button, gpointer arg) 
{
    char temp[1024];
    GtkEntry *entry = (GtkEntry *)arg;
    const char *str = gtk_entry_get_text(entry);
    strcpy(temp, str);
    strcat(temp, "6");
    gtk_entry_set_text(entry, temp);
}

void Seven(GtkButton *button, gpointer arg)
{
    char temp[1024];
    GtkEntry *entry = (GtkEntry *)arg;
    const char *str = gtk_entry_get_text(entry);
    strcpy(temp, str);
    strcat(temp, "7");
    gtk_entry_set_text(entry, temp);
}

void Eight(GtkButton *button, gpointer arg)
{
    char temp[1024];
    GtkEntry *entry = (GtkEntry *)arg;
    const char *str = gtk_entry_get_text(entry);
    strcpy(temp, str);
    strcat(temp, "8");
    gtk_entry_set_text(entry, temp);
}

void Nine(GtkButton *button, gpointer arg)
{
    char temp[1024];
    GtkEntry *entry = (GtkEntry *)arg;
    const char *str = gtk_entry_get_text(entry);
    strcpy(temp, str);
    strcat(temp, "9");
    gtk_entry_set_text(entry, temp);
}

void Point(GtkButton *button, gpointer arg)
{
    char temp[1024];
    GtkEntry *entry = (GtkEntry *)arg;
    const char *str = gtk_entry_get_text(entry);
    strcpy(temp, str);
    strcat(temp, ".");
    gtk_entry_set_text(entry, temp);
}

void Add(GtkButton *button, gpointer arg)
{
    char temp[1024];
    GtkEntry *entry = (GtkEntry *)arg;
    const char *str = gtk_entry_get_text(entry);
    strcpy(temp, str);
    strcat(temp, "+");
    gtk_entry_set_text(entry, temp);
}

void Jian(GtkButton *button, gpointer arg)
{
    char temp[1024];
    GtkEntry *entry = (GtkEntry *)arg;
    const char *str = gtk_entry_get_text(entry);
    strcpy(temp, str);
    strcat(temp, "-");
    gtk_entry_set_text(entry, temp);
}

void Cheng(GtkButton *button, gpointer arg)
{
    char temp[1024];
    GtkEntry *entry = (GtkEntry *)arg;
    const char *str = gtk_entry_get_text(entry);
    strcpy(temp, str);
    strcat(temp, "*");
    gtk_entry_set_text(entry, temp);
}

void Chu(GtkButton *button, gpointer arg)
{
    char temp[1024];
    GtkEntry *entry = (GtkEntry *)arg;
    const char *str = gtk_entry_get_text(entry);
    strcpy(temp, str);
    strcat(temp, "/");
    gtk_entry_set_text(entry, temp);
}

void Clear(GtkButton *button, gpointer arg)
{
    GtkEntry *entry = (GtkEntry *)arg;
    gtk_entry_set_text(entry, "");
}

void Del(GtkButton *button, gpointer arg)
{
    char temp[1024];
    GtkEntry *entry = (GtkEntry *)arg;
    const char *str = gtk_entry_get_text(entry);
    strcpy(temp, str);
    int k = strlen(temp);
    if (k > 0) {
        temp[k-1] = '\0';
        gtk_entry_set_text(entry, temp);
    }
}

// 获取操作数栈顶元素
void GetTop(Char *lchar, char *x)
{
    *x = lchar->c[lchar->top];
}


void Result(GtkButton *button, gpointer *arg)
{
    GtkEntry *entry = (GtkEntry *)arg;
    const char *str = gtk_entry_get_text(entry);
    char temp[100];
    double a = 0;
    double b = 0;
    char x;
    int j = -1;
    int k = strlen(str);
    for (int i = 0; i < k; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            a = b = 0;
            while (i < k && str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && str[i] != '.') {
                a = ((int)str[i] - 48) + a * 10;
                i++;
            }
            if (i < k && str[i] == '.') {
                while (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/') {
                    b = ((int)str[i] - 48) * power(j) + b;
                    j--;
                    i++;
                }
            }
            i--;
            a += b;
            PopNum(&lnum, a);
            a = 0;
            b = 0;
            j = -1;
        } else {
            if (Empty(lchar.top) == EMPTY) {
                PopChar(&lchar, str[i]);
            } else {
                GetTop(&lchar, &x);
                while (Judge(x, str[i]) == MORE) {
                    PushChar(&lchar, &x);
                    PushNum(&lnum, &a);
                    PushNum(&lnum, &b);
                    switch(x) {
                        case '+':
                                a += b;
                                break;
                        case '-':
                                a -= b;
                                break;
                        case '*':
                                a *= b;
                                break;
                        case '/':
                                a /= b;
                                break;
                        default:break;
                    }
                    PopNum(&lnum, a);
                    a = 0;
                    b = 0;
                    if (Empty(lchar.top) == EMPTY) {
                        break;
                    }
                    GetTop(&lchar, &x);
                }
                PushChar(&lchar, str[i]);
            }
        }
    }
    PushChar(&lchar, &x);
    PushNum(&lnum, &a);
    PushNum(&lnum, &b);
        switch(x) {
            case '+':
                    a += b;
                    break;
            case '-':
                    a -= b;
                    break;
            case '*':
                    a *= b;
                    break;
            case '/':
                    a /= b;
                    break;
            default:break;
    }
    lchar.top = -1;
    lnum.top = -1;
    sprintf(temp, "%lf", a);
    gtk_entry_set_text(entry, temp);
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
    // 数据结构初始化
    lnum.top = -1;
    lchar.top = -1;
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title((GtkWindow *)window, "计算器");
    gtk_widget_set_size_request(window, 400, 600);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    // 垂直布局
    GtkWidget *vbox = gtk_vbox_new(TRUE, 10);
    // 表格布局
    GtkWidget *table = gtk_table_new(5, 4, TRUE);
    // 行编辑
    GtkWidget *entry = gtk_entry_new();
    // 将垂直布局加入到window中
    gtk_container_add((GtkContainer *)window, vbox);
    // 将行编辑添加到垂直布局里
    gtk_container_add((GtkContainer *)vbox, entry);
    // 将表格布局添加到垂直布局里
    gtk_container_add((GtkContainer *)vbox, table);
    // 设置按钮
    GtkWidget *button_clear = gtk_button_new_with_label("C");
    GtkWidget *button_del = gtk_button_new_with_label("DEL");
    GtkWidget *button_division = gtk_button_new_with_label("/");
    GtkWidget *button_multiplication = gtk_button_new_with_label("*");
    GtkWidget *button_subtraction = gtk_button_new_with_label("-");
    GtkWidget *button_add = gtk_button_new_with_label("+");
    GtkWidget *button_result = gtk_button_new_with_label("=");
    GtkWidget *button_point = gtk_button_new_with_label(".");
    GtkWidget *button1 = gtk_button_new_with_label("1");
    GtkWidget *button2 = gtk_button_new_with_label("2");
    GtkWidget *button3 = gtk_button_new_with_label("3");
    GtkWidget *button4 = gtk_button_new_with_label("4");
    GtkWidget *button5 = gtk_button_new_with_label("5");
    GtkWidget *button6 = gtk_button_new_with_label("6");
    GtkWidget *button7 = gtk_button_new_with_label("7");  
    GtkWidget *button8 = gtk_button_new_with_label("8");  
    GtkWidget *button9 = gtk_button_new_with_label("9");  
    GtkWidget *button0 = gtk_button_new_with_label("0");
    // 将上面的按钮添加到表格布局中
    gtk_table_attach_defaults((GtkTable *)table, button_clear, 0, 1, 0, 1);
    gtk_table_attach_defaults((GtkTable *)table, button_del, 1, 2, 0, 1);
    gtk_table_attach_defaults((GtkTable *)table, button_division, 2, 3, 0, 1);
    gtk_table_attach_defaults((GtkTable *)table, button_multiplication, 3, 4, 0, 1);
    gtk_table_attach_defaults((GtkTable *)table, button_subtraction, 3, 4, 1, 2);
    gtk_table_attach_defaults((GtkTable *)table, button_add, 3, 4, 2, 3);
    gtk_table_attach_defaults((GtkTable *)table, button_result, 3, 4, 3, 5);
    gtk_table_attach_defaults((GtkTable *)table, button1, 0, 1, 3, 4);
    gtk_table_attach_defaults((GtkTable *)table, button2, 1, 2, 3, 4);
    gtk_table_attach_defaults((GtkTable *)table, button3, 2, 3, 3, 4);
    gtk_table_attach_defaults((GtkTable *)table, button4, 0, 1, 2, 3);
    gtk_table_attach_defaults((GtkTable *)table, button5, 1, 2, 2, 3);
    gtk_table_attach_defaults((GtkTable *)table, button6, 2, 3, 2, 3);
    gtk_table_attach_defaults((GtkTable *)table, button7, 0, 1, 1, 2);
    gtk_table_attach_defaults((GtkTable *)table, button8, 1, 2, 1, 2);
    gtk_table_attach_defaults((GtkTable *)table, button9, 2, 3, 1, 2);
    gtk_table_attach_defaults((GtkTable *)table, button0, 0, 2, 4, 5);
    gtk_table_attach_defaults((GtkTable *)table, button_point, 2, 3, 4, 5);
    // 设置回调函数
    g_signal_connect(button_add, "clicked", G_CALLBACK(Add), entry);
    g_signal_connect(button_clear, "clicked", G_CALLBACK(Clear), entry);
    g_signal_connect(button_del, "clicked", G_CALLBACK(Del), entry);
    g_signal_connect(button_division, "clicked", G_CALLBACK(Chu), entry);
    g_signal_connect(button_multiplication, "clicked", G_CALLBACK(Cheng), entry);
    g_signal_connect(button_subtraction, "clicked", G_CALLBACK(Jian), entry);
    g_signal_connect(button_point, "clicked", G_CALLBACK(Point), entry);
    g_signal_connect(button_result, "clicked", G_CALLBACK(Result), entry);
    g_signal_connect(button1, "clicked", G_CALLBACK(One), entry);
    g_signal_connect(button2, "clicked", G_CALLBACK(Two), entry);
    g_signal_connect(button3, "clicked", G_CALLBACK(Three), entry);
    g_signal_connect(button4, "clicked", G_CALLBACK(Four), entry);
    g_signal_connect(button5, "clicked", G_CALLBACK(Five), entry);
    g_signal_connect(button6, "clicked", G_CALLBACK(Six), entry);
    g_signal_connect(button7, "clicked", G_CALLBACK(Seven), entry);
    g_signal_connect(button8, "clicked", G_CALLBACK(Eight), entry);
    g_signal_connect(button9, "clicked", G_CALLBACK(Nine), entry);
    g_signal_connect(button0, "clicked", G_CALLBACK(Zero), entry);
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

