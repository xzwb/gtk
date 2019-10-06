// 回调函数

#include <stdio.h>
#include <gtk/gtk.h>

// 回调函数类型,gpointer 相当于void *
void fun(GtkButton *button, gpointer arg)
{
    printf("hello world!!\n");
}

int main(int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *button;
    int a = 8;
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request(window, 600, 600);
    button = gtk_button_new_with_label("Hello!");
    gtk_container_add((GtkContainer *)window, button);
    // 调函数第二个参数是操作名称, 第三个参数是掉的函数名,最后一个参数是传递的参数
    g_signal_connect(button, "clicked", G_CALLBACK(fun), NULL);
    // 点击关闭退出gtk_main_quit是库里用来退出gtk_main的
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show_all(window);

    gtk_main();
    return 0;
}

