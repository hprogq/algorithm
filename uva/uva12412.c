#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SUBJ 4
#define MAXL 12
#define PASS 60
#define MAXN 10000
int sum = 0;

typedef struct student {
    long long sid;
    int cid;
    char name[MAXL];
    int score[SUBJ + 1];
    int total_score;
    int status;
} student;
student stu[MAXN];

char *subjects[] = {
    "",
    "Chinese",
    "Mathematics",
    "English",
    "Programming"
};

int add_stu() {
    printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
    long long sid;
    int cid;
    char name[MAXL];
    int score[SUBJ + 1];
    scanf("%lld", &sid);
    if ( sid == 0 )
        return 1;
    scanf("%d %s", &cid, name);
    for ( int i = 1; i <= SUBJ; i++ )
        scanf(" %d", &score[i]);
    for ( int i = 1; i <= sum; i++ )
        if ( stu[i].status && stu[i].sid == sid ) {
            printf("Duplicated SID.\n");
            return 0;
        }
    sum++;
    stu[sum].sid = sid;
    stu[sum].cid = cid;
    strcpy(stu[sum].name, name);
    memcpy(stu[sum].score, score, sizeof(score));
    for ( int i = 1; i <= SUBJ; i++ )
        stu[sum].total_score += score[i];
    stu[sum].status = 1;
    return 0;
}

void show_statistics() {
    printf("Please enter class ID, 0 for the whole statistics.\n");
    int cid;
    scanf("%d", &cid);
    int sumc = 0, s_total[SUBJ + 1] = {0}, s_passed[SUBJ + 1] = {0}, a_passed[SUBJ + 1] = {0};
    for ( int i = 1; i <= sum; i++ )
        if ( stu[i].status && ( !cid || stu[i].cid == cid )) {
            sumc++;
            int passed = 0;
            for ( int j = 1; j <= SUBJ; j++ ) {
                if ( stu[i].score[j] >= PASS )
                    passed++, s_passed[j]++;
                s_total[j] += stu[i].score[j];
            }
            a_passed[passed]++;
        }
    for ( int i = 1; i <= SUBJ; i++ ) {
        if ( sumc )
            printf("%s\nAverage Score: %.2f\nNumber of passed students: %d\nNumber of failed students: %d\n\n", subjects[i], s_total[i] * 1.0 / sumc + 1e-5, s_passed[i], sumc - s_passed[i]);
        else printf("%s\nAverage Score: nan\nNumber of passed students: %d\nNumber of failed students: %d\n\n", subjects[i], s_passed[i], sumc - s_passed[i]);
    }
    printf("Overall:\n");
    int pass_stu = 0;
    for ( int i = SUBJ; i >= 0; i-- ) {
        pass_stu += i == 0 ? 0 : a_passed[i];
        if ( i == SUBJ )
            printf("Number of students who passed all subjects: %d\n", pass_stu);
        else if ( i == 0 )
            printf("Number of students who failed all subjects: %d\n", sumc - pass_stu);
        else printf("Number of students who passed %d or more subjects: %d\n", i, pass_stu);
    }
    printf("\n");
    return;
}

void show_ranklist() {
    printf("Showing the ranklist hurts students' self-esteem. Don't do that.\n");
    return;
}

int get_rank(int id) {
    int rank = 0;
    for ( int i = 1; i <= sum; i++ )
        if ( i != id && stu[i].status && stu[i].total_score > stu[id].total_score )
            rank++;
    return ++rank;
}

int query_stu() {
    printf("Please enter SID or name. Enter 0 to finish.\n");
    char data[30];
    scanf("%s", data);
    if ( strlen(data) == 1 && data[0] == '0' )  
        return 1;
    if ( data[0] >= 'A' && data[0] <= 'Z' ) {
        // Name
        for ( int i = 1; i <= sum; i++ )
            if ( stu[i].status && !strcmp(stu[i].name, data) )
                printf("%d %010lld %d %s %d %d %d %d %d %.2f\n", get_rank(i), stu[i].sid, stu[i].cid, stu[i].name, stu[i].score[1], stu[i].score[2], stu[i].score[3], stu[i].score[4], stu[i].total_score, stu[i].total_score / 4.0 + 1e-5);
    } else {
        // SID
        long long sid = atoll(data);
        for ( int i = 1; i <= sum; i++ )
            if ( stu[i].status && stu[i].sid == sid )
                printf("%d %010lld %d %s %d %d %d %d %d %.2f\n", get_rank(i), stu[i].sid, stu[i].cid, stu[i].name, stu[i].score[1], stu[i].score[2], stu[i].score[3], stu[i].score[4], stu[i].total_score, stu[i].total_score / 4.0 + 1e-5);
    }
    return 0;
}

int remove_stu() {
    printf("Please enter SID or name. Enter 0 to finish.\n");
    char data[30];
    scanf("%s", data);
    if ( strlen(data) == 1 && data[0] == '0' )
        return 1;
    int count = 0;
    if ( data[0] >= 'A' && data[0] <= 'Z' ) {
        // Name
        for ( int i = 1; i <= sum; i++ )
            if ( stu[i].status && !strcmp(stu[i].name, data) )
                stu[i].status = 0, count++;
    } else {
        // SID
        long long sid = atoll(data);
        for ( int i = 1; i <= sum; i++ )
            if ( stu[i].status && stu[i].sid == sid )
                stu[i].status = 0, count++;
    }
    printf("%d student(s) removed.\n", count);
    return 0;
}

void manifest() {
    printf("Welcome to Student Performance Management System (SPMS).\n\n1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\n5 - Show Statistics\n0 - Exit\n\n");
    return;
}

int main( void ) {
#ifdef LOCAL
    freopen("uva12412.in", "r", stdin);
    freopen("uva12412.out", "w", stdout);
#endif
    int command;
    for ( ; ; ) {
        printf("Welcome to Student Performance Management System (SPMS).\n\n1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\n5 - Show Statistics\n0 - Exit\n\n");
        scanf("%d", &command);
        switch (command) {
            case 1:
                while(!add_stu());
                break;
            case 2:
                while(!remove_stu());
                break;
            case 3:
                while(!query_stu());
                break;
            case 4:
                show_ranklist();
                break;
            case 5:
                show_statistics();
                break;
            case 0:
                return 0;
            default:
                break;
        }
    }
    return 0;
}
