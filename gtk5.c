// 表格布局

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
    // 创建表格布局容器
    GtkWidget *table = gtk_table_new(2, 2, TRUE);
    // 将创建的表格布局加到Window里
    gtk_container_add((GtkContainer *)window, table);
    // 将按钮加到表格布局里这时候不再用gtk_container_add
    gtk_table_attach_defaults((GtkTable *)table, button, 0, 1, 0, 1);
    gtk_table_attach_defaults((GtkTable *)table, button1, 1, 2, 0, 1);
    gtk_table_attach_defaults((GtkTable *)table, button2, 0, 1, 1, 2);
    gtk_table_attach_defaults((GtkTable *)table, button3, 1, 2, 1, 2);

    gtk_widget_show_all(window);

    gtk_main();

}
