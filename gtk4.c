// 布局：设定控件的位置大小

#include <stdio.h>
#include <gtk/gtk.h>

/* int main(int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *question;
    GtkWidget *answar1;
    GtkWidget *answar2;
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title((GtkWindow *)window, "Hello!");
    gtk_widget_set_size_request(window, 600, 600);
    question = gtk_button_new_with_label("yyf是最帅的");
    answar1 = gtk_button_new_with_label("no");
    answar2 = gtk_button_new_with_label("yes");
    gtk_widget_set_size_request(question, 20, 20);
    gtk_widget_set_size_request(answar1, 10, 10);
    gtk_widget_set_size_request(answar2, 10, 10);
    gtk_container_add((GtkContainer *)window, question);
    gtk_container_add((GtkContainer *)window, answar1);
    gtk_container_add((GtkContainer *)window, answar2);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show_all(window);

    gtk_main();
    return 0;
} */

// 上面为错误示范

int main(int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *hbox;
    GtkWidget *button;
    GtkWidget *button1;
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title((GtkWindow *)window, "Hello!");
    gtk_widget_set_size_request(window, 600, 600);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    button = gtk_button_new_with_label("hello");
    button1 = gtk_button_new_with_label("world");
    // 创建一个水平布局容器,第二个参数是间距
    hbox = gtk_hbox_new(TRUE, 5);
    // 创建一个标签
    GtkWidget *label = gtk_label_new("1");
    GtkWidget *label1 = gtk_label_new("2");
    // 先把hbox添加到window里
    gtk_container_add((GtkContainer *)window, hbox);
    // 再把两个按钮添加到水平容器hbox中
    gtk_container_add((GtkContainer *)hbox, button);
    gtk_container_add((GtkContainer *)hbox, button1);
    gtk_container_add((GtkContainer *)hbox, label);
    gtk_container_add((GtkContainer *)hbox, label1);
    gtk_widget_show_all(window);

    gtk_main();
    return 0;
}
