#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#include <limits.h> 
#include <stdbool.h> 
#define INFINITY 9999
#define V 10
#define max 10 
#define infinity 999
int matrix[max][max],Q[max];
float theta;
int flag=0;
int path[max],p[max];
int dest,scr,y2,z;
int u=0;
int ans=0;
int scr=0;
int n=10;
int ug;
float x,y;
int matrix[10][10]={
                        {0,85,75,25,45,55,95,65,35,15},
                        {94,0,24,74,34,64,44,14,54,84},
                        {93,33,0,73,53,13,43,63,23,83},
                        {37,87,57,0,47,27,97,77,17,67},
                        {59,49,69,79,0,89,99,19,39,29},
                        {76,56,16,36,46,0,86,66,26,96},
                        {87,27,17,77,67,37,0,47,57,97},
                        {78,28,58,98,18,68,88,0,48,38},
                        {59,69,39,19,49,29,99,79,0,89},
                        {11,61,81,51,21,71,91,31,41,0}
                        };
int coord[10][2]={
						{50,250},
						{500,80},
						{500,470},
						{150,400},
						{250,50},
						{350,450},
						{650,250},
						{350,120},
						{250,310},
						{150,160},
						
				};
void init(void)
		{
		glClearColor(0.0,0.0,0.0,0.0);//specifies the RGB and alpha values used by glClear() to clear the color buffers.
		glMatrixMode(GL_PROJECTION);
		gluOrtho2D(0,700,0,500);
		}
void drawBitmapText(char *string, float x, float y, float z)
		{  
		char *c;
		glRasterPos2f(x, y);
		for (c=string; *c != '\0'; c++)
			{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
			}
		}
void ScanMenu(int id)
		{
		if (id == 1)
		flag = 1;
		if (id == 2)
		flag = 2;
		if (id == 3)
		flag = 3;
		if (id == 4)
		flag =4;		
		logic(flag);
		glutPostRedisplay();
		}
void display()
		{
		int i;
		//node0
		glColor3f(1.0f, 1.0f, 1.0f);
		drawBitmapText("S", 50, 250, 0);
		drawBitmapText("Warehouse", 20, 215, 0);
		glutSwapBuffers();
		glutPostRedisplay();
		
		glPointSize(5);
		glBegin(GL_POINTS);
		glColor3f(1.0,1.0,1.0);
		for( i=0;i<360;i++)
			{
			theta=i*3.142/180;
			glVertex2f(50+18*cos(theta),250+18*sin(theta));
			}
		glEnd();
		
		//node9
		glColor3f(1.0f, 1.0f, 1.0f);
		drawBitmapText("9", 150, 160, 0);
		glutSwapBuffers();
		glutPostRedisplay();
		
		glPointSize(5);
		glBegin(GL_POINTS);
		glColor3f(1.0,1.0,1.0);
		for( i=0;i<360;i++)
			{
			theta=i*3.142/180;
			glVertex2f(150+18*cos(theta),160+18*sin(theta));
			}
		glEnd();
		
		//node3
		glColor3f(1.0f, 1.0f, 1.0f);
		drawBitmapText("3", 150, 400, 0);
		glutSwapBuffers();
		glutPostRedisplay();
		
		glPointSize(5);
		glBegin(GL_POINTS);
		glColor3f(1.0,1.0,1.0);
		for( i=0;i<360;i++)
			{
			theta=i*3.142/180;
			glVertex2f(150+18*cos(theta),400+18*sin(theta));
			}
		glEnd();
		
		///node4
		glColor3f(1.0f, 1.0f, 1.0f);
		drawBitmapText("4", 250, 50, 0);
		glutSwapBuffers();
		glutPostRedisplay();
		
		glBegin(GL_POINTS);
		glPointSize(5);
		glColor3f(1.0,1.0,1.0);
		for( i=0;i<360;i++)
			{
			theta=i*3.142/180;
			glVertex2f(250+18*cos(theta),50+18*sin(theta));
			}
		glEnd();
		
		///node8
		glColor3f(1.0f, 1.0f, 1.0f);
		drawBitmapText("8", 250, 310, 0);
		glutSwapBuffers();
		glutPostRedisplay();
		
		glPointSize(5);
		glBegin(GL_POINTS);
		glColor3f(1.0,1.0,1.0);
		for( i=0;i<360;i++)
			{
			theta=i*3.142/180;
			glVertex2f(250+18*cos(theta),310+18*sin(theta));
			}
		glEnd();
		
		///node7
		glColor3f(1.0f, 1.0f, 1.0f);
		drawBitmapText("7", 350, 120, 0);
		glutSwapBuffers();
		glutPostRedisplay();
		
		glPointSize(5);
		glBegin(GL_POINTS);
		glColor3f(1.0,1.0,1.0);
		for( i=0;i<360;i++)
			{
			theta=i*3.142/180;
			glVertex2f(350+18*cos(theta),120+18*sin(theta));
			}
		glEnd();
		
		////node5
		glColor3f(1.0f, 1.0f, 1.0f);
		drawBitmapText("5", 350, 450, 0);
		glutSwapBuffers();
		glutPostRedisplay();
		
		glPointSize(5);
		glBegin(GL_POINTS);
		glColor3f(1.0,1.0,1.0);
		for( i=0;i<360;i++)
			{
			theta=i*3.142/180;
			glVertex2f(350+18*cos(theta),450+18*sin(theta));
			}
		glEnd();
		
		//node1
		glColor3f(1.0f, 1.0f, 1.0f);
		drawBitmapText("1", 500, 80, 0);
		glutSwapBuffers();
		glutPostRedisplay();
		
		glPointSize(5);
		glBegin(GL_POINTS);
		glColor3f(1.0,1.0,1.0);
		for( i=0;i<360;i++)
			{
			theta=i*3.142/180;
			glVertex2f(500+18*cos(theta),80+18*sin(theta));
			}
		glEnd();
		
		///node2
		glColor3f(1.0f, 1.0f, 1.0f);
		drawBitmapText("2", 500, 470, 0);
		glutSwapBuffers();
		glutPostRedisplay();
		
		glPointSize(5);
		glBegin(GL_POINTS);
		glColor3f(1.0,1.0,1.0);
		for( i=0;i<360;i++)
			{
			theta=i*3.142/180;
			glVertex2f(500+18*cos(theta),470+18*sin(theta));
			}
		glEnd();
		
		///node 6
		glColor3f(1.0f, 1.0f, 1.0f);
		drawBitmapText("6", 650, 250, 0);
		glutSwapBuffers();
		glutPostRedisplay();
		
		glPointSize(5);
		glBegin(GL_POINTS);
		glColor3f(1.0,1.0,1.0);
		for( i=0;i<360;i++)
			{
			theta=i*3.142/180;
			glVertex2f(650+18*cos(theta),250+18*sin(theta));
			}
		glEnd();
		glFlush();
		
		///park
		glColor3f(1.0f, 1.0f, 1.0f);
		drawBitmapText("CITY PARK", 405, 280, 0);
		glutSwapBuffers();
		glutPostRedisplay();
		
		glBegin(GL_LINE_LOOP);
		glVertex2f(350,350);
		glVertex2f(550,350);
		glVertex2f(550,220);
		glVertex2f(350,220);
		glEnd();
		glFlush();
		
		}
	int minKey(int key[], bool mstSet[]) 
			{ 
			    int min = INT_MAX, min_index; 
			  	int v;
			    for ( v = 0; v < V; v++) 
			        if (mstSet[v] == false && key[v] < min) 
			            min = key[v], min_index = v;  
			    return min_index; 
			} 

int printMST(int parent[], int graph[V][V]) 
{ 
    printf("Edge \tWeight\n"); 
    int i;
    for ( i = 1; i < V; i++) 
    {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]); 
        		glBegin(GL_LINES);
				glColor3f(0.0,1.0,0.0);
				glVertex2i(coord[parent[i]][0],coord[parent[i]][1]);
				glVertex2i(coord[i][0],coord[i][1]);
				glEnd();
				glFlush();
				glutSwapBuffers();
	}
} 
void primMST(int graph[V][V]) 
{
    int parent[V]; 
    int key[V]; 
    bool mstSet[V]; 
    int i;
    for ( i = 0; i < V; i++) 
    key[i] = INT_MAX, mstSet[i] = false; 
    key[0] = 0; 
    parent[0] = -1; 
    int count;
    for ( count = 0; count < V - 1; count++) 
	{ 
        int u = minKey(key, mstSet); 
        mstSet[u] = true; 
        int v;
        for ( v = 0; v < V; v++) 
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
                parent[v] = u, key[v] = graph[u][v]; 
    } 
    printMST(parent, graph); 
} 
void dijkstra(int scr,int dest)
	{
	int small,dist[10],current,start,new1;
	int temp,i,a[10];
	void insertq(int);
		for(i=0;i<=n;i++)
		{
		a[i]=0;
		dist[i]=infinity;
		}
		Q[scr]=1;
		dist[scr]=0;
		current=scr;
		while(current!=dest)
		{
		small=infinity;
		start=dist[current];
				for(i=1;i<=n;i++)
				{
						if(Q[i]==0)
						{
						new1=start+matrix[current][i];
									if(new1<dist[i])
									{
									dist[i]=new1;
									insert(i,current);
									}
									if(dist[i]<small)
									{
									small=dist[i];
									temp=i;
									}
						}
				}
		current=temp;
		insertq(current);
		}
	}
	///////////////////////////////////////////insertq
void insertq(int index)
	{
	Q[index]=1;
	}
	//////////////////////////////////////////////insert
void insert(int index,int vertex)
	{
	path[index]=vertex;
	}
int display2(int dest,int scr)
	{
		int z=1;
			while(dest>scr)
			{
				int a;
				a=path[dest];
						if(a!=scr)
						{
						p[z]=a;
						}
						else
						{
						p[z]=a;
						}
				++z;
				dest=a;
			}
			int u=0;
			int r[10],i;	
			for(y2=max;y2>0;y2--)
			{
			if(p[y2]!=infinity)
					{
					printf("%d->",p[y2]);
				glBegin(GL_LINES);
				glColor3f(0.0,1.0,0.0);
				glVertex2i(coord[u][0],coord[u][1]);
				glVertex2i(coord[p[y2]][0],coord[p[y2]][1]);
				
				glEnd();
				glFlush();
				glutSwapBuffers();
				u=p[y2];
				for(i=0;i<10;i++)
				r[i]=p[y2];
					}					
			}
		int t=sizeof(r)/sizeof(int);
		ans=r[t-1];
		return ans;
	}

void logic(int flag)
{
	if(flag==1)
	{
				primMST(matrix); 				
	}
	if (flag==2)
	{
		int i;
		int v2[10];
		int dist[10];
		int location,minimum;
		printf("Enter the number of urgent nodes:");
		scanf("%d",&ug);
		printf("Enter the urgent nodes:");
		for (i=1;i<=ug;i++)
		{	
			scanf("%d",&v2[i]);
			dist[i-1]=matrix[0][v2[i]];	
		}
		
		minimum=dist[0];
		for (i = 1; i < ug; i++)
    		{
		        if (dist[i] < minimum)
		        {
		           minimum = dist[i];
		           location=v2[i+1];
		        }
    		}   
    	printf("distance of nearest urgent node from source is: %d and the node is :%d \n", minimum,location);
    			glBegin(GL_LINES);
				glColor3f(0.0,1.0,0.0);
				glVertex2i(coord[0][0],coord[0][1]);
				glVertex2i(coord[location][0],coord[location][1]);
				glEnd();
				glFlush();
				glutSwapBuffers();	
	}
	if(flag==3)
	{
		int nodeNumber;
		int cost[10][10], distance[10], pred[10];
		int visited[10], count, mindistance, nextnode, i,j;
		for(i=0;i < 10;i++)
			for(j=0;j < 10;j++)
				if(matrix[i][j]==0)
					cost[i][j]=INFINITY;
				else
			cost[i][j]=matrix[i][j];		
		for(i=0;i< 10;i++)
			{
			distance[i]=cost[0][i];
			pred[i]=0;
			visited[i]=0;
			}
		distance[0]=0;
		visited[0]=1;
		count=1;
		while(count < 9)
			{
			mindistance=INFINITY;
			for(i=0;i < 10;i++)
			if(distance[i] < mindistance&&!visited[i])
				{
				mindistance=distance[i];
				nextnode=i;
				}
			visited[nextnode]=1;
			for(i=0;i < 10;i++)
			if(!visited[i])
			if(mindistance+cost[nextnode][i] < distance[i])
				{
				distance[i]=mindistance+cost[nextnode][i];
				pred[i]=nextnode;
				}
			count++;
			}
			printf("\nEnter the node to be visited");
			scanf("%d",&nodeNumber);
			if(nodeNumber!=0)
			{
				printf("\nDistance of %d = %d", nodeNumber, distance[nodeNumber]);
				printf("\nPath = %d", nodeNumber);
				j=nodeNumber;
				glBegin(GL_LINES);
				glColor3f(0.0,1.0,0.0);
				glVertex2i(coord[nodeNumber][0],coord[nodeNumber][1]);
				glVertex2i(coord[pred[j]][0],coord[pred[j]][1]);
				glEnd();
				glFlush();
				glutSwapBuffers();
			  do
				{				
				j=pred[j];
				printf(" <-%d", j);
				glBegin(GL_LINES);
				glColor3f(0.0,1.0,0.0);
				glVertex2i(coord[pred[j]][0],coord[pred[j]][1]);
				glVertex2i(coord[j][0],coord[j][1]);
				glEnd();
				glFlush();
				glutSwapBuffers();
				}
			while(j!=0);				
			}
	}
	if (flag==4)
	{
		printf("\nEnter the destination: ");
		scanf("%d",&dest);
		dijkstra(0,dest);
		for(y2=1;y2<=max;y2++)
		p[y2]=infinity;
		printf("\nThe shortest path is:\n\t");
		display2(dest,scr);
		printf("%d",dest);
		glBegin(GL_LINES);
				glColor3f(0.0,1.0,0.0);				
				glVertex2i(coord[ans][0],coord[ans][1]);
				glVertex2i(coord[dest][0],coord[dest][1]);
				glEnd();
				glFlush();
				glutSwapBuffers();
		getch();
	}		
}
int main(int argc , char** argv)
{
	int choice;
    printf("Minor-1\n");
    printf("VARIANTS OF TRAVELLING SALESMAN PROBLEM TO OPTIMIZE HAULAGE FOR EFFICIENT MARKETING\n");
	glutInit(&argc , argv);//initialize glut library
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);//picture code drawing directly on the display
	glutInitWindowPosition(100,100);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("minor project 1");
	init();//projection specifications
	glutDisplayFunc(display);//to draw the city map 
	glutCreateMenu(ScanMenu);// to get the choices 
	glutAddMenuEntry("1. Map to deliver all the orders with minimum cost.", 1);
	glutAddMenuEntry("2. Prefer urgent orders", 2);
	glutAddMenuEntry("3. Shortest path for a particular order (time complexity O(N^2)", 3);
	glutAddMenuEntry("4. Shortest path for a particular order (time complexity O(ElogV)", 4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}

