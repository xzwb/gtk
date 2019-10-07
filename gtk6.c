// 固定布局

#include <stdio.h>
#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *button1;
    GtkWidget *button2;
    GtkWidget *button3;
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title((GtkWindow *)window, "hello!");
    gtk_widget_set_size_request(window, 600, 600);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    button = gtk_button_new_with_label("hello");
    button1 = gtk_button_new_with_label("hello1");
    button2 = gtk_button_new_with_label("hello2");
    button3 = gtk_button_new_with_label("hello3");
    // 创建固定布局
    GtkWidget *fixed = gtk_fixed_new();
    gtk_container_add((GtkContainer *)window, fixed);
    gtk_fixed_put((GtkFixed *)fixed, button, 100, 100);
    // 设置控件大小
    gtk_widget_set_size_request(button, 100, 100);
    gtk_widget_show_all(window);

    gtk_main();
}
