/*versatile downloading solution code named Leviathan
started developing 12/15/2025
Location M-cafe*/

//Project: Programming fundamentals lab
//Submitted to: Noor fatima 
//submitted on: 23/12/2025
/*======================================================
25021556-130     Sidra Asghar 
25021556-162     Muhammad Bilal
25021556-167     Maliqa 
25021556-175     Muhammad Ibraheem
GITHUB:https://github.com/Effectforward/Leviathan
========================================================*/

#include <stdio.h>
#include<string.h>
#include <stdlib.h>//to use system(); and sprintf(); and exit();
//global variables so that we don't have to implement them individually in each function
char url[405];//variable to store the url of YouTube link (string)
char command[5000]; 
int c;//variable to flush the buffer
 /*
we are using arrays to store strings because they allow us to modify them afterwards
if we use char *str = "something";
We will be unable to modify the values of them when dealing with addition of url within the strings,
 in our case sprintf(); won't work with that
 */


//written by bilal
void youtubevideos();//function to download youtube videos via ytdlp
void spotify();//function to download spotify music via spotdl 
void aria2c();//function to download everything else via aria2 
void help();//fucntion to display manual 


int main(){
	while(1){
	int choice = 0;
	
printf("\n   ===LEVIATHAN DOWNLOADER ===\n");
    printf("   [01] Youtube Content\n");
    printf("   [02] Spotify Stream\n");
    printf("   [03] Aria Protocol\n");
    printf("   [04] System Help\n");
    printf("   [05] Terminate\n\n");
   
    printf("   (root@leviathan)\n");
    printf("   Selection: ");
    
    
   

	scanf ("%d",&choice);
    while ((c = getchar()) != '\n' && c != EOF);
	//special condition for exiting and spotify
	if (choice==1 || choice==3 )
//	goto continuation;
{
    printf("   Enter url: ");
    //scanf is very unsafe to use so we are using fgets
    fgets(url,400,stdin);
    url[strcspn(url, "\n")] = 0;
	//switch case code written by bilal line 26-46
    //to flush the input stream:
     //Flush input
    }
	//continuation:
	switch(choice){
		case 1:
			youtubevideos();
			break;
            
				case 2:
					spotify();
					break;
                    
						case 3:
							aria2c();
							break;
                            
								case 4:
								    help();
								    break;
                                    
									    case 5:
										    printf("See you later\n");
										    return 0;
										     //exit(EXIT_FAILURE);
											break;
										        default:
                                                choice = 0;
												printf("Invalid choice\n");
	}
	
}
return 0;	
}

//definition of youtubevideos();

//youtubevideos(); function written at 10:00 p.m Wed,Dec 17 2025 by effectforward
void youtubevideos() {
/*It uses yt-dlp to parse the link and download the video/playlist*/
 
    int choice;

    //printf("1. 240p\n2. 360p\n3. 480p\n4. 720p\n5. 1080p\n6. Highest\nChoice: ");
    
    
    printf("   [1] 240p\n");
    printf("   [2] 360p\n");
    printf("   [3] 480p\n");
    printf("   [4] 720p\n");
    printf("   [5] 1080p\n");
    printf("   [6] Highest Available\n\n");
    printf("   Selection: ");
    
    scanf("%d", &choice);
    while ((c = getchar()) != '\n' && c != EOF);
    //to flush the input stream
    /*
    sprintf(); used to create the final command string that is gonna be 
    parsed to system();
    It simply works same as printf but instead of printing on the console
    it stores that string in memory
    */
    
    
    
    switch(choice)  
{
    case 1: // 240p
        snprintf(command, sizeof(command), "yt-dlp -f \"bestvideo[height<=240]+bestaudio/best\" \"%s\"", url);
        break;

    case 2: // 360p
        snprintf(command, sizeof(command), "yt-dlp -f \"bestvideo[height<=360]+bestaudio/best\" \"%s\"", url);
        break;

    case 3: // 480p
        snprintf(command, sizeof(command), "yt-dlp -f \"bestvideo[height<=480]+bestaudio/best\" \"%s\"", url);
        break;

    case 4: // 720p
        snprintf(command, sizeof(command), "yt-dlp -f \"bestvideo[height<=720]+bestaudio/best\" \"%s\"", url);
        break;

    case 5: // 1080p
        snprintf(command, sizeof(command), "yt-dlp -f \"bestvideo[height<=1080]+bestaudio/best\" \"%s\"", url);
        break;

    case 6: // Highest Available
        snprintf(command, sizeof(command), "yt-dlp -f \"bestvideo+bestaudio/best\" \"%s\"", url);
        break;

    default:
        // Simple download without any format flags
        snprintf(command, sizeof(command), "yt-dlp \"%s\"", url);
        break;
}
    system(command);
}



//definition of spotify();

//spotify(); function written for Leviathan universal downloader
//written by Maliqa
void spotify() {
/*For taking name or url we are declaring it 
inside fumction */
//to flush the input stream so that there are no conflicts regarding the /n that scanf puts at the end
    
printf("Enter URL or name of the song: [Artist - song name] \n\t");

//A better option is to use fgets
fgets(url,400,stdin);
url[strcspn(url, "\n")] = 0;
 snprintf(command, sizeof(command), 
            "spotdl download \"%s\" --log-level DEBUG --save-file \"spotdl_progress.spotdl\"", url);
            system(command);
 
}
//written by sidra asghar
void aria2c()
{
sprintf(command, 
    "aria2c -x 16 -s 16 -k 1M -c "
    "--file-allocation=falloc "
    "--retry-wait=10 --max-tries=0 "
    "--user-agent=\"Mozilla/5.0 (Windows NT 10.0; Win64; x64)\" "
    "--disk-cache=64M "
    "--console-log-level=warn "
    "--enable-http-pipelining=true "
    "\"%s\"", url);
        system (command);
        }
        
        //written by sidra
        void help() {
    printf("\n==============================================================\n");
    printf("                LEVIATHAN: SYSTEM USER MANUAL                 \n");
    printf("==============================================================\n\n");

    printf("1. YOUTUBE MODULE (yt-dlp)\n");
    printf("   - Usage: Paste link -> Select resolution.\n");
    printf("   - Technicals: Uses format logic 'bestvideo+bestaudio'. It pulls\n");
    printf("     the highest quality tracks and merges them into an MP4 container.\n\n");

    printf("2. SPOTIFY MODULE (spotdl)\n");
    printf("   - Usage: Paste link or type 'Artist - Song'.\n");
    printf("   - Technicals: Uses '--save-file' to create a resume point.\n");
    printf("   - Layman Note: Use 'User Auth' if you get errors or want to\n");
    printf("     download your own private playlists.\n\n");

    printf("3. ARIA PROTOCOL (aria2c)\n");
    printf("   - Usage: Best for direct links (Large ZIPs, ISOs, EXEs).\n");
    printf("   - Technicals: Uses 16 simultaneous connections (-x 16) and \n");
    printf("     HTTP Pipelining. This bypasses server-side speed caps.\n");
    printf("   - Layman Note: This is the fastest downloader in the suite.\n\n");

    printf("4. SYSTEM REQUIREMENTS\n");
    printf("   - Ensure yt-dlp, spotdl, and aria2c are in your PATH.\n");
    printf("   - ffmpeg is REQUIRED for audio/video merging to work.\n");
    printf("______________________________________________________________\n");

    printf("\nPress [ENTER] to return to menu...");
    getchar(); // Wait for user
    system ("cls");
}
	printf("4.help\n");
	printf("5.exit\n");
    printf("Enter choice:\n");
    
    /*
    // Clear Screen & Reset
    // printf("\e[1;1H\e[2J");
    //including this line causes to clear the screen automatically after the error is occured 
   // --- MENU: Minimalist List ---
   printf("\033[1;36m   [01]\033[0m Youtube Content\n");
   printf("\033[1;36m   [02]\033[0m Spotify Stream\n");
   printf("\033[1;36m   [03]\033[0m Aria Protocol\n");
   printf("\033[1;36m   [04]\033[0m System Help\n");
   printf("\033[1;31m   [05]\033[0m Terminate\n\n");
   
   // --- INPUT: Prompt Style ---
   printf("\033[1;30m   +--(\033[1;34muser@leviathan\033[1;30m)-[\033[0m~/\033[1;30m]\n");
   printf("   +-\033[1;36m$\033[0m selection: ");
   // Source - https://stackoverflow.com/a
   // Posted by Evan Mulawski, modified by community. See post 'Timeline' for change history
   // Retrieved 2025-12-19, License - CC BY-SA 3.0
   
   //scanf("%d *[^\n]", &choice);
   */
   

	scanf ("%d",&choice);
    while ((c = getchar()) != '\n' && c != EOF);
	//special condition for exiting and spotify
	if (choice==1 || choice==3 )
//	goto continuation;
{
    printf("Enter url:\n");
    //scanf is very unsafe to use so we are using fgets
    fgets(url,400,stdin);
    url[strcspn(url, "\n")] = 0;
	//switch case code written by bilal line 26-46
    //to flush the input stream:
     //Flush input
    }
	//continuation:
	switch(choice){
		case 1:
			youtubevideos();
			break;
            
				case 2:
					spotify();
					break;
                    
						case 3:
							aria2c();
							break;
                            /*
								case 4:
								    help();
								    break;
                                    */
									    case 5:
										    printf("See you later\n");
										    return 0;
										     //exit(EXIT_FAILURE);
											break;
										     default:
                                             choice = 0;
												printf("Invalid choice\n");
	}
	
}
return 0;	
}

//definition of youtubevideos();

//youtubevideos(); function written at 10:00 p.m Wed,Dec 17 2025 by effectforward
void youtubevideos() {
/*It uses yt-dlp to parse the link and download the video/playlist*/
 
    int choice;

    printf("1. 240p\n2. 360p\n3. 480p\n4. 720p\n5. 1080p\n6. Highest\nChoice: ");
    scanf("%d", &choice);
    while ((c = getchar()) != '\n' && c != EOF);
    //to flush the input stream
    /*
    sprintf(); used to create the final command string that is gonna be 
    parsed to system();
    It simply works same as printf but instead of printing on the console
    it stores that string in memory
    */
    
    
    
    switch(choice)  
{
    case 1: // 240p
        snprintf(command, sizeof(command), "yt-dlp -f \"bestvideo[height<=240]+bestaudio/best\" \"%s\"", url);
        break;

    case 2: // 360p
        snprintf(command, sizeof(command), "yt-dlp -f \"bestvideo[height<=360]+bestaudio/best\" \"%s\"", url);
        break;

    case 3: // 480p
        snprintf(command, sizeof(command), "yt-dlp -f \"bestvideo[height<=480]+bestaudio/best\" \"%s\"", url);
        break;

    case 4: // 720p
        snprintf(command, sizeof(command), "yt-dlp -f \"bestvideo[height<=720]+bestaudio/best\" \"%s\"", url);
        break;

    case 5: // 1080p
        snprintf(command, sizeof(command), "yt-dlp -f \"bestvideo[height<=1080]+bestaudio/best\" \"%s\"", url);
        break;

    case 6: // Highest Available
        snprintf(command, sizeof(command), "yt-dlp -f \"bestvideo+bestaudio/best\" \"%s\"", url);
        break;

    default:
        // Simple download without any format flags
        snprintf(command, sizeof(command), "yt-dlp \"%s\"", url);
        break;
}
    system(command);
}



//definition of spotify();

//spotify(); function written for Leviathan universal downloader
void spotify() {
/*For taking name or url we are declaring it 
inside fumction */
//to flush the input stream so that there are no conflicts regarding the /n that scanf puts at the end
    
printf("Enter URL or name of the song: [Artist - song name] \n");
/*
scanf(" %[^\n]", url); 
Here the purpose of using [^\n] is that if we
use %s it won't read spaces for example (link abc)
it will read link but skip abc*/

//A bettet option is to use fgets
fgets(url,400,stdin);
url[strcspn(url, "\n")] = 0;
int choice;
printf("1.With user authentication\n");
printf("2.without user authentication\n");

printf("Enter your choice : \n");
scanf("%d", &choice);

  switch(choice)  
{
    case 1:
        // Download with Debug, Progress File, and User Auth
        snprintf(command, sizeof(command), 
            "spotdl download \"%s\" --log-level DEBUG --save-file \"spotdl_progress.spotdl\" --user-auth", url);
        break;
  
    case 2:
        // Download with Debug and Progress File
        snprintf(command, sizeof(command), 
            "spotdl download \"%s\" --log-level DEBUG --save-file \"spotdl_progress.spotdl\"", url);
        break;
    
    default:
        // Simple download (no extra flags)
        snprintf(command, sizeof(command), "spotdl download \"%s\"", url);
        break;
}
system(command);
}

void aria2c()
{
sprintf(command, 
    "aria2c -x 16 -s 16 -k 1M -c "
    "--file-allocation=falloc "
    "--retry-wait=10 --max-tries=0 "
    "--user-agent=\"Mozilla/5.0 (Windows NT 10.0; Win64; x64)\" "
    "--disk-cache=64M "
    "--console-log-level=warn "
    "--enable-http-pipelining=true "
    "\"%s\"", url);
        system (command);
        }
