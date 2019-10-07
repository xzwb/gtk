// 综合布局和行编辑

#include <stdio.h>
#include <gtk/gtk.h>

void button_add(GtkButton *button, gpointer arg)
{
     
}

int main(int argc, char *argv[]) 
{
    gtk_init(&argc, &argv);
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title((GtkWindow *)window, "hello");
    gtk_widget_set_size_request(window, 600, 600);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    GtkWidget *button_add = gtk_button_new_with_label("add");
    GtkWidget *button_del = gtk_button_new_with_label("del");
    GtkWidget *button_print = gtk_button_new_with_label("print");
    // 垂直布局
    GtkWidget *vbox = gtk_vbox_new(TRUE, 5);
    // 水平布局
    GtkWidget *hbox = gtk_hbox_new(TRUE, 5);
    // 行编辑
    GtkWidget *entry = gtk_entry_new();
    gtk_container_add((GtkContainer *)window, vbox);
    gtk_container_add((GtkContainer *)vbox, entry);    
    gtk_container_add((GtkContainer *)vbox, hbox);
    gtk_container_add((GtkContainer *)hbox, button_add);    
    gtk_container_add((GtkContainer *)hbox, button_del);
    gtk_container_add((GtkContainer *)vbox, button_print);
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
