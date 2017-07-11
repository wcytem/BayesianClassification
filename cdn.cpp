#include "deploy.h"
#include "./lib/lib_io.h"
#include "./lib/lib_time.h"
#include "stdio.h"

int main(int argc, char *argv[])
{
    argv = new char *[3];
    argv[0] = "";
    argv[1] = "E:/MyProjects/Matlab/MyCode/CDNPlacementAlg/case_example/2/1.txt";
    argv[2] = "E:/MyProjects/Matlab/MyCode/CDNPlacementAlg/answers/2/1.txt";
    float lamda = 0.7f;

    print_time("Begin");
    char *topo[MAX_EDGE_NUM];
    int line_num;
   
    char *topo_file = argv[1];

    line_num = read_file(topo, MAX_EDGE_NUM, topo_file);

    printf("line num is :%d \n", line_num);
    if (line_num == 0)
    {
        printf("Please input valid topo file.\n");
        return -1;
    }

    char *result_file = argv[2];

    CCDN cdn(topo, line_num, result_file);
    
    cdn.DeployServer(lamda);

    release_buff(topo, line_num);

    print_time("End");

	return 0;
}

