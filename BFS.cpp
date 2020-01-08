#include <stdio.h>
#include <limits.h>
#define MAX 110
 
int N;//지도 크기
int map[MAX][MAX];//지도 정보
int visited[MAX][MAX]; // 방문여부
 
int dc[] = { 1, -1, 0, 0 };
int dr[] = { 0, 0, 1, -1 };
 
typedef struct {
    int r, c; // price
} ROAD;
 
ROAD q[MAX*MAX*MAX];
int wp, rp;
 
void push(int r, int c) {
    q[wp].r = r;
    q[wp++].c = c;
}
 
void pop(ROAD* p) {
    p->r = q[rp].r;
    p->c = q[rp++].c;
}
 
void Input_Data(void){
    int r, c;
    wp=rp=0;
    scanf("%d", &N);
    for(r = 0 ; r < N ; r++){
        for(c=0; c<N; c++) {
            scanf("%1d", &map[r][c]);
            visited[r][c] = INT_MAX;
        }
    }
}
 
int valid(int r, int c, int p) {
    if ( r < 0 || r >= N || c < 0 || c >= N) return 0; // boundary 벗어나
    if ( visited[r][c] <= p ) return 0;
    return 1;
}
 
int BFS() {
    ROAD road;
    int nr, nc, np;
     
    push(0, 0);
    visited[0][0] = map[0][0];
     
    while (rp<wp) {
        pop(&road);
        //if ( (road.x == N-1) && (road.y == N-1) ) return visited[N-1][N-1];
         
        for(int i=0; i<4; i++) {
            nc = road.c + dc[i];
            nr = road.r + dr[i];
            np = visited[road.r][road.c] + map[nr][nc];
            if(!valid(nr,nc,np)) continue;
            push(nr, nc);
            visited[nr][nc] = np;
        }
    }
     
    return visited[N-1][N-1];
     
}
 
int main(void){
    int ans = -1;
    Input_Data();       //  입력 함수
     
    //  코드를 작성하세요
    ans = BFS();
     
    printf("%d\n", ans);        //  정답 출력
 
    return 0;
}