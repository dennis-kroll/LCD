

#include "gui/guiapp_resources.h"
#include "gui/guiapp_specifications.h"

#include "main_thread.h"

//static bool button_enabled = false;
uint8_t n=0;
char eingabe[10];

//extern GX_WINDOW_ROOT * p_window_root;

//static UINT show_window(GX_WINDOW * p_new, GX_WIDGET * p_widget, bool detach_old);
static void update_text_id(GX_WIDGET * p_widget, GX_RESOURCE_ID id, UINT string_id);

UINT window1_handler(GX_WINDOW *widget, GX_EVENT *event_ptr)
{
    UINT result = gx_window_event_process(widget, event_ptr);

    switch (event_ptr->gx_event_type)
    {
    case GX_SIGNAL(enter_1, GX_EVENT_CLICKED):
            eingabe[n]='1';
            n++;
            break;
    case GX_SIGNAL(enter_2, GX_EVENT_CLICKED):
            eingabe[n]='2';
            n++;
            break;
    case GX_SIGNAL(enter_3, GX_EVENT_CLICKED):
            eingabe[n]='3';
            n++;
            break;
    case GX_SIGNAL(enter_4, GX_EVENT_CLICKED):
            eingabe[n]='4';
            n++;
            break;
    case GX_SIGNAL(enter_5, GX_EVENT_CLICKED):
            eingabe[n]='5';
            n++;
            break;
    case GX_SIGNAL(enter_6, GX_EVENT_CLICKED):
            eingabe[n]='6';
            n++;
            break;
    case GX_SIGNAL(enter_7, GX_EVENT_CLICKED):
            eingabe[n]='7';
            n++;
            break;
    case GX_SIGNAL(enter_8, GX_EVENT_CLICKED):
            eingabe[n]='8';
            n++;
            break;
    case GX_SIGNAL(enter_9, GX_EVENT_CLICKED):
            eingabe[n]='9';
            n++;
            break;
    case GX_SIGNAL(enter_0, GX_EVENT_CLICKED):
            eingabe[n]='0';
            n++;
            break;
    case GX_SIGNAL(enter, GX_EVENT_CLICKED):

             //gxe.gx_event_target = ID_TXT_INPUT;
            //button_enabled = true;
            //update_text_id(widget->gx_widget_parent, enter, "" );

            //eingabe[n]="1";
            //n++;
            break;
    case GX_SIGNAL(enter_N, GX_EVENT_CLICKED):
            eingabe[n]='N';
            n++;
            break;
    case GX_SIGNAL(enter_S, GX_EVENT_CLICKED):
            eingabe[n]='S';
            n++;
            break;
    /*case GX_SIGNAL(ID_BUTTONENABLER, GX_EVENT_TOGGLE_OFF):
        button_enabled = false;
        update_text_id(widget->gx_widget_parent, ID_WINDOWCHANGER, GX_STRING_ID_BUTTON_DISABLED);
        update_text_id(widget->gx_widget_parent, ID_INSTRUCTIONS, GX_STRING_ID_INSTRUCT_CHECKBOX);
        break;
    case GX_SIGNAL(ID_WINDOWCHANGER, GX_EVENT_CLICKED):
        if(button_enabled){
            show_window((GX_WINDOW*)&window2, (GX_WIDGET*)widget, true);
        }
        break;*/
    default:
        gx_window_event_process(widget, event_ptr);
        update_text_id(widget->gx_widget_parent, anzeige2, eingabe);
        break;
    }

    return result;
}


/*
static UINT show_window(GX_WINDOW * p_new, GX_WIDGET * p_widget, bool detach_old)
{
    UINT err = GX_SUCCESS;

    if (!p_new->gx_widget_parent)
    {
        err = gx_widget_attach(p_window_root, p_new);
    }
    else
    {
        err = gx_widget_show(p_new);
    }

    gx_system_focus_claim(p_new);

    GX_WIDGET * p_old = p_widget;
    if (p_old && detach_old)
    {
        if (p_old != (GX_WIDGET*)p_new)
        {
            gx_widget_detach(p_old);
        }
    }

    return err;
}
*/
static void update_text_id(GX_WIDGET * p_widget, GX_RESOURCE_ID id, UINT string_id)
{
    GX_PROMPT * p_prompt = NULL;

    ssp_err_t err = gx_widget_find(p_widget, (USHORT)id, GX_SEARCH_DEPTH_INFINITE, (GX_WIDGET**)&p_prompt);
    if (TX_SUCCESS == err)
    {
        gx_prompt_text_set(p_prompt, string_id);
    }
}



