#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
struct face{
char f1[10],f2[10],f3[10],f4[10],name[256],serihu[256],p[10],c1[10],c2[10],c3[10],c4[10];
};

char *color(int i) { 
switch (i) {
case 1:return "\x1b[30m"; // Black
case 2:return "\x1b[31m"; // Red
case 3:return "\x1b[32m"; // Green
case 4:return "\x1b[33m"; // Yellow
case 5:return "\x1b[34m"; // Blue
case 6:return "\x1b[35m"; // Magenta
case 7:return "\x1b[36m"; // Cyan
case 8:return "\x1b[37m"; // White
    }
}

char *sindan(){
int a[5],p[4];
int ok=0;
char b[][30]={"行動は","言葉は","表情は","考え方は","はっきり言って"};
char c[][20]={"ゆっくり","マイルド","クール","慎重","個性的"};
char d[][20]={"キビキビ","ストレート","豊か","楽観的","常識人"};
printf("性格診断テストを始めます。\n");
do{
for(int i=0;i<5;i++){
printf("%s...%s...1/%s...2/\n",b[i],c[i],d[i]);
if(scanf("%d",&a[i])!=1){printf("文字列が入力されました\n");}
if(a[i]!=1&&a[i]!=2){
printf("範囲外の値が入力されました\n");
ok=1;}}
}while(ok==1);
for(int i=0;i<5;i++){
if(a[i]==2)
a[i]=-1;}
p[0]=2*a[0]-5*a[1]-3*a[2]-4*a[3]-4*a[4];
p[1]=2*a[0]+5*a[1]+4*a[2]+4*a[3]+4*a[4];
p[2]=3*a[0]+3*a[1]+5*a[2]-2*a[3]-10*a[4];
p[3]=-4*a[0]-4*a[1]+a[2]+5*a[3]+6*a[4];
int max=p[0];
 for(int i=0; i<5; i++){
   if(max<p[i])
      max=p[i];}
if(max==p[0]){printf("ノリ系です。\n");return "1";}
else if(max==p[1]){printf("クール系です。\n");return "2";}
else if(max==p[2]){printf("ナゴミ系です。\n");return "3";}
else if(max==p[3]){printf("ドライ系です。\n");return "4";}

}

void make(struct face *s,int v,int w,int e){//vはf1から4のどれを使うかを示す。
FILE *sfp; // コピー元のファイル
FILE *dfp; // コピー先のファイル
char a[15];
char c[15];
char b[15]=".txt";
switch(v){
case 1: strcpy(a,(*s).f1);strcpy(c,"hair"); break;
case 2: strcpy(a,(*s).f2);strcpy(c,"eye"); break;
case 3: strcpy(a,(*s).f3);strcpy(c,"nose"); break;
case 4: strcpy(a,(*s).f4);strcpy(c,"mouse"); break;
}
char t[15];
strcat(c, a);
strcat(c, b);
strcpy(t,c);
if(w==0&&v!=5){
if ((sfp = fopen(t, "r")) == NULL)
printf("コピー元ファイルをオープンできません。番号を文字列で打ち込んでいませんか。\n");
else {
if ((dfp = fopen((*s).name, "a")) == NULL)
printf("コピー先ファイルをオープンできません。\n");
else {
int ch;
while ((ch = fgetc(sfp)) != EOF)
fputc(ch, dfp);
fclose(dfp);
}
fclose(sfp);

if(v==1&&e==1){
FILE *fp;
if ((fp = fopen("list.txt", "a")) == NULL)
printf("ファイルをオープンできません。\n");
else {
fprintf(fp,"%s %s %s\n",(*s).name,(*s).serihu,(*s).p);
fclose(fp);
}
}}}

else{//色変え
FILE *fp;
if ((fp = fopen(t, "r")) == NULL)
printf("コピー元ファイルをオープンできません。\n");
else {
int ch;
while ((ch = fgetc(fp)) != EOF){
printf("%s",color(w));
putchar(ch);
printf("\x1b[39m");
}}}}

void set(struct face *s, int a)
{char c[10];
switch(a){
case 1:printf("髪のパーツの番号を入力してください。");  scanf("%s",(*s).f1);break;
case 2:printf("目のパーツの番号を入力してください。");  scanf("%s",(*s).f2);break;
case 3:printf("鼻のパーツの番号を入力してください。");  scanf("%s",(*s).f3);break;
case 4:printf("口のパーツの番号を入力してください。");  scanf("%s",(*s).f4);break;
case 5:printf("作ったアバターにニックネームをつけてください。");  scanf("%s",(*s).name);break;
case 6:printf("作ったアバターの性格を教えてください。ノリ系...1/クール系...2/ナゴミ系...3/ドライ系...4/性格診断をする...5:");scanf("%s",c);
       if(strcmp(c,"5")==0) {
       strcpy((*s).p,sindan());break;}
       else {strcpy((*s).p,c);break;}
case 7:printf("作ったアバターの口癖を教えてください。");  scanf("%s",(*s).serihu);break;
}
}

int main(void)
{
int r;
do{
printf("ユウジンコレクションへようこそ。\nモードを選んでください。アバター制作モード...1/住民観察モード...2/会話モード...3:");
if(scanf("%d",&r)!=1){printf("文字列が入力されました\n");return 1;}
if(r!=1&&r!=2&&r!=3)
printf("範囲外の値が入力されました\n");
}while(r!=1&&r!=2&&r!=3);
if(r==1){
printf("catalog.txtを開いてください。\n髪、目、鼻、口のパーツを選んでください。\n");
struct face p;
for(int i=0;i<7;i++){
set(&p,i+1);}
for(int i=0;i<4;i++){
make(&p,i+1,0,1);}//name.txt出力

int k,w,retry;
printf("作ったアバターがファイル出力されました。\nパーツを変えますか？Yes...1/No...2:");
if(scanf("%d",&k)!=1){printf("文字列が入力されました\n");return 1;}
if(k==1) {
do{
char c[15];
strcpy(c,p.name);
remove(c);
do{
printf("どのパーツを変えますか？髪...1/目...2/鼻...3/口...4:");
if(scanf("%d",&w)!=1){printf("文字列が入力されました\n");return 1;}
if(w!=1&&w!=2&&w!=3&&w!=4)
printf("範囲外の値が入力されました\n");
}while(w!=1&&w!=2&&w!=3&&w!=4);
switch(w){
case 1:set(&p,1);break;
case 2:set(&p,2);break;
case 3:set(&p,3);break;
case 4:set(&p,4);break;
}
for(int i=0;i<4;i++){
make(&p,i+1,0,0);}
do{
printf("もう一度？Yes...1/No...2:");
if(scanf("%d",&retry)!=1){printf("文字列が入力されました\n");return 1;}
if(retry!=1&&retry!=2)
printf("範囲外の値が入力されました\n");
}while(retry!=1&&retry!=2);
}while(retry==1);
}

printf("作ったアバターに色をつけましょう。");
int l[4];
int ok=0;
char parts[][5]={"髪","目","鼻","口"};
do{
for(int i=0;i<4;i++){
printf("%sの色は何にしますか。\n黒...1/赤...2/緑...3/黃...4/青...5/紫...6/水色...7/白...8:\n",parts[i]);
if(scanf("%d",&l[i])!=1){printf("文字列が入力されました\n");return 1;}
if(l[i]!=1&&l[i]!=2&&l[i]!=3&&l[i]!=4&&l[i]!=5&&l[i]!=6&&l[i]!=7&&l[i]!=8){
printf("範囲外の値が入力されました\n");
ok=1;}}
}while(ok==1);
for(int i=0;i<4;i++){
make(&p,i+1,l[i],0);}}

if(r==2){
char i[][30]={"喧嘩している","遊んでいる","デートしている！"};
char h[][30]={"ご飯を食べている","寝ている","勉強している","留守している"};
FILE *fp;
if ((fp=fopen("list.txt", "r"))==NULL)
printf("ファイルをオープンできません。\n");
else {
char mi[256],ri[256],yi[256];//miは観察したいアバターのニックネーム、riはファイルから読み取ったニックネーム、yiはランダムに選ばれたニックネームを入れる変数。
int j=0;
int u=0;
printf("生活の様子を観察したいアバターのニックネームを教えてください。");  scanf("%s",mi);
while (fscanf(fp, "%s %*s %*s", ri) == 1){
 u++;//ファイルからニックネームを読み取るごとにuを1増やす。uはファイルからニックネームを読み取った回数を表す。
 if(strcmp(mi,ri)==0)//観察したいアバターのニックネームがファイルから読み取ったニックネームと一致したとき。
 j=1;
 else if(rand() % 10>7){
 strcpy(yi,ri);//観察したいアバターと違うアバターのニックネームをランダムに選ぶ。
srand(time(NULL)); }
 if(u==1){
 strcpy(yi,ri);}
}
srand(time(NULL)); 
if(j==0)
printf("そのアバターは存在しません。");
else if(u==1||strcmp(yi,ri)==0){
printf("%sは%s",mi,h[rand() % 4]);
srand(time(NULL)); }
else if(rand() % 10>4){
printf("%sは%s",mi,h[rand() % 4]);
srand(time(NULL)); }
else
printf("%sは%sと%s",mi,yi,i[rand() % 3]);
fclose(fp);
}
}

if(r==3){
char hello[][30]={"こんにちは!!","こんにちは...","こんにちはー","こんにちは"};//あいさつ
char eat[][40]={"いただきます。","大好物だったようです。","おいしかったようです。","苦手だったようです..."};//食事の反応
char react[][40]={"ありがとうございます。","すごく気に入ったようです。","気に入ったようです。","気に入らなかったようです"};//プレゼントの反応
char laugh[][30]={"はははは！","ふふふ...","あははー","はは"};//面白い話をしたときの反応
char b[][30]={"またね!！","さよなら...","さよーなら","じゃ"};//別れのあいさつ
char za[][100]={"好きなものは一番初めに食べます。","ひとりでいると、落ち着きます。","日曜日は寝て過ごしたいです。","だらだらするのが嫌いです。","貯金はしなくてもなんとかなると思います。","ちまちましたことをするのが好きです","のんびり暮らしたいです。","理不尽なことは許せません。","友達を100人作るのが夢です。","たまには外に出ないといけませんね。","実は、小さなことですぐ落ち込みます。","ほめることが苦手です。"};//雑談のネタ
FILE *fp;
if ((fp=fopen("list.txt", "r"))==NULL)
printf("ファイルをオープンできません。\n");
else {
char mp[256],si[256],ss[256],ri[256],se[10],sp[10];
int j=0;
printf("会話したいアバターのニックネームを教えてください。");  scanf("%s",mp);
while (fscanf(fp, "%s %s %s",ri ,ss,sp) == 3){
 if(strcmp(mp,ri)==0){
strcpy(se,sp);
strcpy(si,ss);
 j=1;}}
if(j==0)
printf("そのアバターは存在しません。");
else{
printf("%s:%s\n何を話しますか。",mp,hello[atoi(se)-1]);
int w;
do{
do{
printf("\n面白い話をする...1/なにか喋ってよ...2/ご飯をあげる...3/プレゼントをあげる...4/会話をやめる.../5:");
if(scanf("%d",&w)!=1){printf("文字列が入力されました\n");return 1;}
if(w!=1&&w!=2&&w!=3&&w!=4&&w!=5)
printf("範囲外の値が入力されました\n");
}while(w!=1&&w!=2&&w!=3&&w!=4&&w!=5);
char some[256];
switch(w){
case 1:printf("あなた:");scanf("%s",some);
       printf("%s",laugh[atoi(se)-1]);break;
case 2:if(rand()%2==0){printf("%s:%s",mp,za[4*(rand() % 2)+atoi(se)-1]);srand(time(NULL));}
       else{printf("%s:%s",mp,si);} break;
case 3:printf("何をあげますか。");  scanf("%s",some);
       printf("%sに%sをあげました。\n",mp,some);
       printf("%s:%s\n",mp,eat[0]);
       printf("%s:%s",mp,eat[rand()%3+1]);srand(time(NULL));break;
case 4:printf("何をあげますか。");  scanf("%s",some);
       printf("%sに%sをあげました。\n",mp,some);
       printf("%s:%s\n",mp,react[0]);
       printf("%s:%s",mp,react[rand()%3+1]);srand(time(NULL));break;
case 5:printf("%s:%s",mp,b[atoi(se)-1]);break;
}
}while(w!=5);
}}}
return 0;
}

