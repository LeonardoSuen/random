//
//  日历.c
//  计算器
//
//  Created by 孙宇 on 2018/9/19.
//  Copyright © 2018年 孙宇. All rights reserved.
//

/**
 *             `hddddddddddddd-
 *              /MMMMMMMMMMMMMd`
 *               oMMMMMMMMMMMMMs
 *                yMMMMMMMMMMMMM/
 *                `dMMMMMMMMMMMMN.
 *                 .mMMMMMMMMMMMMd`
 *                  -NMMMMMMMMMMMMo
 *                  `mMMMMMMMMMMMMM:
 *                  yMMMMMMMMMMMMMMN.
 *                 sMMMMMMMMMMMMMMMMh
 *                +MMMMMMMMMMMMMMMMMMo
 *               :MMMMMMMMMMMMMMMMMMMM-
 *              .NMMMMMMMMMMMMMMMMMMMMm`
 *             `mMMMMMMMMMMMMMMMMMMMMMMy
 *            `dMMMMMMMMMMMMMMMMMMMMMMMM+
 *            yMMMMMMMMMMMMsMMMMMMMMMMMMM-
 *           oMMMMMMMMMMMMo dMMMMMMMMMMMMm`
 *          +MMMMMMMMMMMMm` -MMMMMMMMMMMMMy
 *         :NMMMMMMMMMMMM:   oMMMMMMMMMMMMM/
 *        .NMMMMMMMMMMMMh    `dMMMMMMMMMMMMN.
 *       `mMMMMMMMMMMMMN.     -MMMMMMMMMMMMMd`
 *      `hMMMMMMMMMMMMMo       sMMMMMMMMMMMMMs
 *      yMMMMMMMMMMMMMm`       `mMMMMMMMMMMMMM/
 *     oMMMMMMMMMMMMMM/         :MMMMMMMMMMMMMN.
 *    /MMMMMMMMMMMMMMh           sMMMMMMMMMMMMMh`
 *   :NMMMMMMMMMMMMMN.           `mMMMMMMMMMMMMMo
 *   yddddddddddddddo             :dddddddddddddh.
 */

#include <stdio.h>
int week;
int year,month;
int suanweek(year,month){   //计算当月第一天是星期几
    int day;
    if(year%400==0||(year%4==0&&year%100!=0)){  //闰年
        switch(month){
            case 1:day=1;
                break;
            case 2:day=31+1;
                break;
            case 3:day=31+29+1;
                break;
            case 4:day=31+29+31+1;
                break;
            case 5:day=31+29+31+30+1;
                break;
            case 6:day=31+29+31+30+31+1;
                break;
            case 7:day=31+29+31+30+31+30+1;
                break;
            case 8:day=31+29+31+30+31+30+31+1;
                break;
            case 9:day=31+29+31+30+31+30+31+31+1;
                break;
            case 10:day=31+29+31+30+31+30+31+31+30+1;
                break;
            case 11:day=31+29+31+30+31+30+31+31+30+31+1;
                break;
            case 12:day=31+29+31+30+31+30+31+31+30+31+30+1;
                break;
        }
    }
    else{   //平年
        switch(month){
            case 1:day=1;
                break;
            case 2:day=31+1;
                break;
            case 3:day=31+28+1;
                break;
            case 4:day=31+28+31+1;
                break;
            case 5:day=31+28+31+30+1;
                break;
            case 6:day=31+28+31+30+31+1;
                break;
            case 7:day=31+28+31+30+31+30+1;
                break;
            case 8:day=31+28+31+30+31+30+31+1;
                break;
            case 9:day=31+28+31+30+31+30+31+31+1;
                break;
            case 10:day=31+28+31+30+31+30+31+31+30+1;
                break;
            case 11:day=31+28+31+30+31+30+31+31+30+31+1;
                break;
            case 12:day=31+28+31+30+31+30+31+31+30+31+30+1;
                break;
        }
    }
    week=((year-1)*365+((year-1)/4)-((year-1)/100)+((year-1)/400)+day)%7;
    return week;
}//suanweek


int main(){
LOOP:printf("请输入查询的年月：\n");
    scanf("%d\t%d",&year,&month);
    printf("\n");
    printf("%d年%d月\n",year,month);
    printf("日\t一\t二\t三\t四\t五\t六\n");
    
    int meiyuedays=0;
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
        meiyuedays=31;
    }
    else if(month==4||month==6||month==9||month==11){
        meiyuedays=30;
    }
    else if(month==2){
        if(year%400==0||(year%4==0&&year%100!=0)){
            meiyuedays=29;
        }//闰年2月的天数
        else{
            meiyuedays=28;
        }
    }
    
    int diyiweek;
    diyiweek=suanweek(year,month);
    for(int i=0;i<diyiweek;i++){
        printf("\t");
    }
    for(int j=1;j<=meiyuedays;j++){
        printf("%d\t",j);
        if((j+diyiweek)%7==0){
            printf("\n");
        }
    }
    
    printf("\n\n");
    goto LOOP;
    return 0;
}
