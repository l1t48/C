#include "ui.h"
#include "io.h"
#include "analyze.h"

//
// Private
//
static void ui_invalid_input()
{
	printf("\x1b[34minfo\x1b[0m> \x1b[31mbad input\x1b[0m\n");
}

static void ui_exit()
{
	printf("\x1b[34minfo \x1b[0m> \x1b[33mExiting...\x1b[0m\n");
}

static char ui_get_choice()
{
	char buf[3];

	printf("\x1b[34minput\x1b[0m> ");
	return read_line(buf, 3) ? buf[0] : 0;
}

static void ui_line(char c, int n)
{
    printf("\x1b[38;5;165m\x1b[1m");
	while (n-- > 0) {
		putchar(c);
	}
	putchar('\n');
    putchar('\n');
    printf("\x1b[0m");
}

static void ui_menu_options(const char *options[], int num_options)
{
	int i;
	for (i=0; i<num_options; i++) {
		printf("   %c) %s\n", 'a'+i, options[i]); 
	}
}


static void ui_menu()
{ 
    // TODO: complete menu
    ui_line('=', MENU_WIDTH);
	const char *options[] = {
		"Menu\x1b[31m",
		"\x1b[1mExit\n\x1b[0m\x1b[32m", 
		"\x1b[3mBubble sort best case\x1b[31m",
        "Bubble sort worst case\x1b[38;5;226m",
        "Bubble sort average case\x1b[32m\n",
        "Insertion sort best case\x1b[31m",
        "Insertion sort worst case\x1b[38;5;226m",
        "Insertion sort average case\x1b[32m\n",
        "Quick sort best case\x1b[31m",
        "Quick sort worst case\x1b[38;5;226m",
        "Quick sort average case\x1b[32m\n",
        "Linear search best case\x1b[31m",
        "Linear search worst case\x1b[38;5;226m",
        "Linear search average case\x1b[32m\n",
        "Binary search best case\x1b[31m",
        "Binary search worst case\x1b[38;5;226m",
        "Binary search average case\x1b[0m\x1b[1m\x1b[39;5;165m\n",
        "Clear the terminal"
	};
    
    printf("\x1b[38;5;165m");
	ui_menu_options(options, sizeof(options) / sizeof(char *));
    printf("\x1b[0m");

    ui_line('=', MENU_WIDTH);
}



static void ui_printResults(const result_t *results, int numResults, const case_t c, const algorithm_t a) {

    for (int i = 0; i < numResults; i++) {
        if(a == bubble_sort_t){
            switch(c){
                case best_t:
                printf("\x1b[32m\x1b[1m%d\t%.8f(s)\t%e(T/logn)\t%e(T/n)\t%e(T/nlogn)\x1b[0m\n\n",
                results[i].size,
                results[i].time,
                results[i].time / log(results[i].size),
                results[i].time / results[i].size,
                results[i].time / (results[i].size * log(results[i].size))); 
                break;
                    
                case worst_t:
                printf("\x1b[31m\x1b[1m%d\t%.8f(s)\t%e(T/nlogn)\t%e(T/n^2)\t%e(T/n^3)\x1b[0m\n\n",
                results[i].size,
                results[i].time,
                results[i].time / (results[i].size * log(results[i].size)),
                results[i].time / pow(results[i].size, 2),
                results[i].time / pow(results[i].size, 3)); 
                break;
                    
                case average_t:
                printf("\x1b[33m\x1b[1m%d\t%.8f(s)\t%e(T/nlogn)\t%e(T/n^2)\t%e(T/n^3)\x1b[0m\n\n",
                results[i].size,
                results[i].time,
                results[i].time / (results[i].size * log(results[i].size)),
                results[i].time / pow(results[i].size, 2),
                results[i].time / pow(results[i].size, 3)); 
                break;
                    
            }
        }

        if(a == insertion_sort_t){
            switch(c){
                case best_t:
                printf("\x1b[32m\x1b[1m%d\t%.8f(s)\t%e(T/logn)\t%e(T/n)\t%e(T/nlogn)\x1b[0m\n\n",
                results[i].size,
                results[i].time,
                results[i].time / log(results[i].size),
                results[i].time / results[i].size,
                results[i].time / (results[i].size * log(results[i].size))); 
                break;
                    
                case worst_t:
                printf("\x1b[31m\x1b[1m%d\t%.8f(s)\t%e(T/nlogn)\t%e(T/n^2)\t%e(T/n^3)\x1b[0m\n\n",
                results[i].size,
                results[i].time,
                results[i].time / (results[i].size * log(results[i].size)),
                results[i].time / pow(results[i].size, 2),
                results[i].time / pow(results[i].size, 3)); 
                break;
                    
                case average_t:
                printf("\x1b[33m\x1b[1m%d\t%.8f(s)\t%e(T/nlogn)\t%e(T/n^2)\t%e(T/n^3)\x1b[0m\n\n",
                results[i].size,
                results[i].time,
                results[i].time / (results[i].size * log(results[i].size)),
                results[i].time / pow(results[i].size, 2),
                results[i].time / pow(results[i].size, 3)); 
                break;
                    
            }
        }

        if(a == quick_sort_t){
            switch(c){
                case best_t:
                printf("\x1b[32m\x1b[1m%d\t%.8f(s)\t%e(T/n)\t%e(T/nlogn)\t%e(T/n^2)\x1b[0m\n\n",
                results[i].size,
                results[i].time,
                results[i].time / results[i].size,
                results[i].time / (results[i].size * log(results[i].size)),
                results[i].time / pow(results[i].size, 2)); 
                break;
                    
                case worst_t:
                printf("\x1b[31m\x1b[1m%d\t%.8f(s)\t%e(T/nlogn)\t%e(T/n^2)\t%e(T/n^3)\x1b[0m\n\n",
                results[i].size,
                results[i].time,
                results[i].time / (results[i].size * log(results[i].size)),
                results[i].time / pow(results[i].size, 2),
                results[i].time / pow(results[i].size, 3)); 
                break;
                    
                case average_t:
                printf("\x1b[33m\x1b[1m%d\t%.8f(s)\t%e(T/n)\t%e(T/nlogn)\t%e(T/n^2)\x1b[0m\n\n",
                results[i].size,
                results[i].time,
                results[i].time / results[i].size,
                results[i].time / (results[i].size * log(results[i].size)),
                results[i].time / pow(results[i].size, 2)); 
                break;
                    
            }
        }

        if(a == linear_search_t){
            switch(c){
                case best_t:
                printf("\x1b[32m\x1b[1m%d\t%.8f(s)\t%e(T/1)\t%e(T/1)\t%e(T/logn)\x1b[0m\n\n",
                results[i].size,
                results[i].time,
                results[i].time / 1,
                results[i].time / 1,
                results[i].time / log(results[i].size)); 
                break;
                    
                case worst_t:
                printf("\x1b[31m\x1b[1m%d\t%.8f(s)\t%e(T/logn)\t%e(T/n)\t%e(T/nlogn)\x1b[0m\n\n",
                results[i].size,
                results[i].time,
                results[i].time / log(results[i].size),
                results[i].time / results[i].size,
                results[i].time / (results[i].size * log(results[i].size))); 
                break;
                    
                case average_t:
                printf("\x1b[33m\x1b[1m%d\t%.8f(s)\t%e(T/logn)\t%e(T/n)\t%e(T/nlogn)\x1b[0m\n\n",
                results[i].size,
                results[i].time,
                results[i].time / log(results[i].size),
                results[i].time / results[i].size,
                results[i].time / (results[i].size * log(results[i].size))); 
                break;
                    
            }
        }

        if(a == binary_search_t){

            switch(c){
                case best_t:
                printf("\x1b[32m\x1b[1m%d\t%.8f(s)\t%e(T/1)\t%e(T/1)\t%e(T/logn)\x1b[0m\n\n",
                results[i].size,
                results[i].time,
                results[i].time / 1,
                results[i].time / 1,
                results[i].time / log(results[i].size)); 
                break;
                    
                case worst_t:
                printf("\x1b[31m\x1b[1m%d\t%.8f(s)\t%e(T/1)\t%e(T/logn)\t%e(T/n)\x1b[0m\n\n",
                results[i].size,
                results[i].time,
                results[i].time / 1,
                results[i].time / log(results[i].size),
                results[i].time / results[i].size); 
                break;
                    
                case average_t:
                printf("\x1b[33m\x1b[1m%d\t%.8f(s)\t%e(T/1)\t%e(T/logn)\t%e(T/n)\x1b[0m\n\n",
                results[i].size,
                results[i].time,
                results[i].time / 1,
                results[i].time / log(results[i].size),
                results[i].time / results[i].size); 
                break;
                    
            }
        }
    }

    ui_line('-', MENU_WIDTH);
}

static void printTheTitle(const case_t c, char *algorithmTitle){
    if(c == best_t){
        printf("\n\x1b[32m\x1b[3m\x1b[1m%s\x1b[0m\n\n", algorithmTitle);
    }

    if(c == worst_t){
        printf("\n\x1b[31m\x1b[3m\x1b[1m%s\x1b[0m\n\n", algorithmTitle);
    }
    if(c == average_t){
        printf("\n\x1b[33m\x1b[3m\x1b[1m%s\x1b[0m\n\n", algorithmTitle);
    }
    ui_line('-', MENU_WIDTH);
}


static void clearTerminal() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}


//
// Public
//
void ui_run()
{
	bool running, show_menu;
	result_t result[RESULT_ROWS];
	
	show_menu = true;
	running = true;
	while (running) {
		if (show_menu) {
			show_menu = false;
			ui_menu();
		}
		switch (ui_get_choice()) {
			// House keeping
			case 'a':
				show_menu = true;
				break;
			case 'b':
				running = false;
				break;
		// Bubble sort
        //-------------------------------------------------------------------
                
            //Best
			case 'c':
				benchmark(bubble_sort_t, best_t, result, RESULT_ROWS);
                printTheTitle(best_t, "Bubble sort best case:");
                ui_printResults(result, RESULT_ROWS, best_t, bubble_sort_t);
				break;
                
            //Worst    
            case 'd':
                benchmark(bubble_sort_t, worst_t, result, RESULT_ROWS);
                printTheTitle(worst_t, "Bubble sort worst case:");
                ui_printResults(result, RESULT_ROWS, worst_t, bubble_sort_t);
				break;
              
            //Average    
            case 'e':
                benchmark(bubble_sort_t, average_t, result, RESULT_ROWS);
                printTheTitle(average_t, "Bubble sort average case:");
                ui_printResults(result, RESULT_ROWS, average_t, bubble_sort_t);
				break;
                
         //-------------------------------------------------------------------
                
                
         // Insertion    
         //-------------------------------------------------------------------
                
            //Best
			case 'f':
                benchmark(insertion_sort_t, best_t, result, RESULT_ROWS);
                printTheTitle(best_t, "Insertion sort best case:");
                ui_printResults(result, RESULT_ROWS, best_t, insertion_sort_t);
				break;
                
            //Worst    
            case 'g':
                benchmark(insertion_sort_t, worst_t, result, RESULT_ROWS);
                printTheTitle(worst_t, "Insertion sort worst case:");
                ui_printResults(result, RESULT_ROWS, worst_t, insertion_sort_t);
				break;
              
            //Average    
            case 'h':
                benchmark(insertion_sort_t, average_t, result, RESULT_ROWS);
                printTheTitle( average_t, "Insertion sort average case:");
                ui_printResults(result, RESULT_ROWS, average_t, insertion_sort_t);
				break;
                
            //-------------------------------------------------------------------
                
            
            //Quick sort
            //-------------------------------------------------------------------
                
            //Best
			case 'i':
                benchmark(quick_sort_t, best_t, result, RESULT_ROWS);
                printTheTitle(best_t, "Quick sort best case:");
                ui_printResults(result, RESULT_ROWS, best_t, quick_sort_t);
				break;
                
            //Worst    
            case 'j':
                benchmark(quick_sort_t, worst_t, result, RESULT_ROWS);
                printTheTitle(worst_t, "Quick sort worst case:");
                ui_printResults(result, RESULT_ROWS, worst_t, quick_sort_t);
				break;
              
            //Average    
            case 'k':
                benchmark(quick_sort_t, average_t, result, RESULT_ROWS);
                printTheTitle( average_t, "Quick sort average case:");
                ui_printResults(result, RESULT_ROWS, average_t, quick_sort_t);
				break;
                
            //-------------------------------------------------------------------
                
                
            //Linear search
            //-------------------------------------------------------------------
                
            //Best
			case 'l':
                benchmark(linear_search_t, best_t, result, RESULT_ROWS);
                printTheTitle(best_t, "Linear search best case:");
                ui_printResults(result, RESULT_ROWS, best_t, linear_search_t);
				break;
                
            //Worst    
            case 'm':
                benchmark(linear_search_t, worst_t, result, RESULT_ROWS);
                printTheTitle(worst_t, "Linear search worst case:");
                ui_printResults(result, RESULT_ROWS, worst_t, linear_search_t);
				break;
              
            //Average    
            case 'n':
                benchmark(linear_search_t, average_t, result, RESULT_ROWS);
                printTheTitle(average_t, "Linear search average case:");
                ui_printResults(result, RESULT_ROWS, average_t, linear_search_t);
				break;
                
            //-------------------------------------------------------------------
                
            
            //Binary search
            //-------------------------------------------------------------------
                
            //Best
			case 'o':
                benchmark(binary_search_t, best_t, result, RESULT_ROWS);
                printTheTitle(best_t, "Binary search best case:");
                ui_printResults(result, RESULT_ROWS, best_t, binary_search_t);
				break;
                
            //Worst    
            case 'p':
                benchmark(binary_search_t, worst_t, result, RESULT_ROWS);
                printTheTitle(worst_t, "Binary search worst case:");
                ui_printResults(result, RESULT_ROWS, worst_t, binary_search_t);
				break;
              
            //Average    
            case 'q':
                benchmark(binary_search_t, average_t, result, RESULT_ROWS);
                printTheTitle(average_t, "Binary search average case:");
                ui_printResults(result, RESULT_ROWS, average_t, binary_search_t);
				break;
            
            //-------------------------------------------------------------------

            case 'r':
                clearTerminal();
                ui_menu();
                break;

			// Invalid input
			default:
				show_menu = false;
				ui_invalid_input();
				break;
		}
	}
	ui_exit();
}
