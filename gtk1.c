#include <stdio.h>
#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
    // 设置窗口
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    // 设置标题
    gtk_window_set_title((GtkWindow *)window, "Hello World!");
    // 设置窗口大小
    gtk_widget_set_size_request(window, 400, 400);
    // 不可伸缩，默认可伸缩
    gtk_window_set_resizable((GtkWindow *)window, FALSE);
    // 窗口在显示器位置,第二个参数GTK_WIN_POS_...4种NONE不固定 CENTER居中 MOUSE鼠标位置CENTER_ALWAYS总是居中
    gtk_window_set_position((GtkWindow *)window, GTK_WIN_POS_MOUSE);
    gtk_widget_show(window);

    
    gtk_main();
    return 0;
}
