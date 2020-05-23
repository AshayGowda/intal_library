#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
static char* remv_zero(char *q, int number)
{
    int index = -1;
    int j = 0;
    while(j < number )
    {
        if (q[j] != '0') 
        {
            index = j;
            break;
        }
        j++;
    }
    if (index == -1)
     {
        strcpy(q,"0");
        return q;
    }
    char b[number-index];
    int k=0;
    while(k < number - index)
    {
        b[k] = q[index + k];
        k++;
    }
    b[k]='\0';
    strcpy(q,b);
    return q;
}

static int int_conv(char var) {
  return (int)(var - 48);
}

static char char_conv(int ele) {
  return (char)(ele + 48);
}

char* intal_add(const char* intal1,const char* intal2) {
  int m = strlen(intal1);
  int n = strlen(intal2);

  int l = (m > n)? m + 1: n + 1;
  int s = (m > n)? n: m;
 
  int i, o, p, q, c = 0;
  char* ans = (char*)malloc((l + 1) * sizeof(char));

  for(i = 0 ; i < s; ++i)
   {
    o = int_conv(intal1[m - 1 - i]);
    p = int_conv(intal2[n - 1 - i]);

    q = o + p + c;
    c = (q > 9)? 1: 0;
    q = (q > 9)? q - 10: q;

    ans[l - 1 - i] = char_conv(q);
  }

  while(i < l - 1) {
    if(m > n) {
      q = int_conv(intal1[m - 1 - i]) + c;
      c = (q > 9)? 1: 0;
      q = (q > 9)? q - 10: q;

      ans[l - 1 - i] = char_conv(q);
    } else {
      q = int_conv(intal2[n - 1 - i]) + c;
      c = (q > 9)? 1: 0;
      q = (q > 9)? q - 10: q;

      ans[l - 1 - i] = char_conv(q);
    }

    ++i;
  }

  if(c != 0) {
    ans[0] = char_conv(c);
    ans[l] = '\0';
  } else {
    for(i = 0; i < l - 1; ++i) {
      ans[i] = ans[i + 1];
    }

    ans = (char*)realloc(ans, l * sizeof(char));
    ans[l - 1] = '\0';
  }

  return ans;
}


int intal_compare(const char* intal1, const char* intal2)
{
int a=strlen(intal1);
int b=strlen(intal2);
int z=0;
if(a>b)
    z=1;
if(a<b)
    z=-1;
if(a==b)
{
    int r=0;
    while(r<a)
    {
        if(intal1[r]>intal2[r])
        {
            z=1;
            break;
        }
        if(intal1[r]<intal2[r])
        {
            z=-1;
            break;
}
r++;
    }
    if(r==a)
        z=0;
}
return z;
}


char* intal_diff(const char* intal1, const char* intal2)
{

int comp_res= intal_compare(intal1,intal2);
    int a = strlen(intal1), b = strlen(intal2);

if(comp_res==1){
int k=0;
    int subs = a - b;
    int car = 0;
  char ans[a];
    for (int i=b-1; i>=0; i--)
    {
        int substr = ((intal1[i+subs]-'0') -
                   (intal2[i]-'0') -
                   car);
        if (substr < 0)
        {
            substr = substr+10;
            car = 1;
        }
        else
            car = 0;
 
        ans[k]=substr+'0';
k++;
    }
    for (int i=a-b-1; i>=0; i--)
    {
        if (intal1[i]=='0' && car)
        {
            ans[k]='9';
k++;
            continue;
        }
        int substr = ((intal1[i]-'0') - car);
        if (i>0 || substr>0) {
            ans[k]=substr+'0';
k++;
}
        car = 0;
 
    }
ans[k]='\0';
char *ans1=(char *)malloc((sizeof(char))*(a));
int l=0;
for(int i=(strlen(ans))-1;i>=0;i--)
{
ans1[l]=ans[i];
l++;
}
ans1[l]='\0';
ans1=remv_zero(ans1,strlen(ans1));
return ans1;
}
if(comp_res==-1){
int l=0;
    int subs = b - a;
    int car = 0;
  char ans[b];
    for (int i=a-1; i>=0; i--)
    {
        int substr = ((intal2[i+subs]-'0') -
                   (intal1[i]-'0') -
                   car);
        if (substr < 0)
        {
            substr = substr+10;
            car = 1;
        }
        else
            car = 0;
 
        ans[l]=substr+'0';
l++;
    }
    for (int i=b-a-1; i>=0; i--)
    {
        if (intal2[i]=='0' && car)
        {
            ans[l]='9';
l++;
            continue;
        }
        int substr = ((intal2[i]-'0') - car);
        if (i>0 || substr>0) {
            ans[l]=substr+'0';
l++;
}
        car = 0;
 
    }
ans[l]='\0';
char *ans1=(char *)malloc((sizeof(char))*(b));
int y=0;
for(int i=(strlen(ans))-1;i>=0;i--)
{
ans1[y]=ans[i];
y++;
}
ans1[y]='\0';
ans1=remv_zero(ans1,strlen(ans1));
return ans1;
}
else
{
if(comp_res==0)
{
char *b=(char *)malloc((sizeof(char))*2);
strcpy(b,"0");
return b;
}
}
char *res=(char *)malloc(sizeof(char)*2);
strcpy(res,"0");
return res;
}


char* intal_multiply(const char* intal1, const char* intal2)
{
if (intal1[0]=='0' || intal2[0]=='0')
    {
char *z=(char *)malloc((sizeof(char))*2);
strcpy(z,"0");
return z;
}
    int st1 = strlen(intal1);
    int st2 = strlen(intal2);

int ans[st1+st2+1];
int f=0;
while(f<st1+st2+1){
ans[f]=0;
f++;
}
    int m_n1 = 0;  
    int m_n2 = 0;  
    for (int i=st1-1; i>=0; i--)
    {
        int car = 0;
        int mz = intal1[i] - '0';
        m_n2 = 0;              
        for (int j=st2-1; j>=0; j--)
        {  
            int my = intal2[j] - '0';
            int sum = mz*my + (ans[m_n1 + m_n2]) + car;
            car = sum/10;
            ans[m_n1 + m_n2] = (sum % 10);
            m_n2++;
        }
        if (car > 0)
            ans[m_n1 + m_n2] =(ans[m_n1 + m_n2]+car);
        m_n1++;
    }  
   
 
int ans1[st1+st2+1];
int k=0;
int i=0;
int d=st1+st2-1;
while(d>=0)
{
ans1[k]=ans[d];
k++;
d--;
}


char* ans2 = (char *)calloc((st1+st2+1),(sizeof(char)));
while(i<(st1+st2))
{
ans2[i]=ans1[i]+'0';
i++;
}
ans2[i]='\0';
ans2=remv_zero(ans2,strlen(ans2));
return ans2;
}

char* intal_mod(char* intal1, char* intal2) {
  int comp_res = intal_compare(intal1, intal2);
  if(comp_res == -1) 
  {
    char* ans = (char*)malloc((strlen(intal1) + 1) * sizeof(char));
    strcpy(ans, intal1);
    return ans;
  } 
  else if(comp_res == 0) 
  {
    char* ans = (char*)malloc((2) * sizeof(char));
    strcpy(ans, "0");
    return ans;
  }

  int w = strlen(intal2);
  int termin = strlen(intal1);
  char* curr = (char*)malloc((strlen(intal2) + 2) * sizeof(char));

  int f=0;
while(f < w)
{
    curr[f] = intal1[f];
     ++f;
}
  curr[w] = '\0';

  do {
    if(intal_compare(curr, intal2) == -1 && w < termin) {
      int st_len = strlen(curr);
      if(strcmp(curr, "0") == 0)
        st_len = 0;
      curr[st_len] = intal1[w];
      curr[st_len + 1] = '\0';
      ++w;
    }

    if(intal_compare(curr, intal2) != -1){
      char* ans = intal_diff(curr, intal2);
      while(intal_compare(ans, intal2) > -1) {
        char* tmp = ans;
        ans = intal_diff(ans, intal2);
        free(tmp);
      }
      
      strcpy(curr, ans);
      free(ans);
    }    
  } while(w < termin);

  curr = realloc(curr, (strlen(curr) + 1) * sizeof(char));
  curr[strlen(curr) + 1] = '\0';
  return curr;
}


char* intal_gcd(const char* intal1, const char* intal2)
{
char* ans = (char*)malloc(sizeof(char)*1001);
    strcpy(ans,"0");
if((0==strcmp(intal1,"0")) && (0==strcmp(intal2,"0")) )
    return ans;

if((0==strcmp(intal1,"0")))
{
strcpy(ans,intal2);
return ans;
}
if((0==strcmp(intal2,"0")))
{
strcpy(ans,intal1);
return ans;
}
char m[1001];
char n[1001];
strcpy(m,intal1);
strcpy(n,intal2);
char* f;
while(strcmp(n,"0")!=0)
{
f=intal_mod(m,n);
strcpy(m,n);
strcpy(n,f);
free(f);

}
strcpy(ans,m);
return ans;
}


char* intal_factorial(unsigned int n)
{
if(n==0 || n==1)
{
char *ans=(char *)malloc(2*sizeof(char));
strcpy(ans,"1");
return ans;
}
char o[1001]="1";
char curr[10];
char *ans;
int i=2;
while(i<=n)
{
sprintf(curr,"%d",i);
ans=intal_multiply(o,curr);
strcpy(o,ans);
free(ans);
i++;
}
char *ans1=(char*)malloc(1001*sizeof(char));
strcpy(ans1,o);
return ans1;
}





char* intal_fibonacci(unsigned int n)
{
if(n==0){
char *ans=(char *)malloc(2*sizeof(char));
strcpy(ans,"0");
return ans;
}

if(n==1){
char *ans=(char *)malloc(2*sizeof(char));
strcpy(ans,"1");
return ans;
}


char before[1001]="0";
char after[1001]="1";
int i=2;
while(i<=n){
char *ans=intal_add(before,after);
strcpy(before,after);
strcpy(after,ans);
free(ans);
i++;
}

char *ans2=(char *)malloc(sizeof(char)*1001);
strcpy(ans2,after);
return ans2;
}




char* intal_bincoeff(unsigned int n, unsigned int k) {
int h=n-k;
if(h<k)
 k=h;
  char** s = (char**)malloc((k+1) * sizeof(char*));
  int f=0;
  while(f < k + 1) {
    s[f] = (char*)malloc(2 * sizeof(char));
    s[f][0] = '0';
    s[f][1] = '\0';
    ++f;
  }

  s[0][0] = '1';

  for(int i = 1; i < n + 1; ++i) {
    int j = (i > k)? k: i;
    while(j > 0) {
      char* tmp = s[j];
      s[j] = intal_add(s[j], s[j - 1]);
      free(tmp);
      --j;
    }
  }

  char* ans = (char*)malloc((strlen(s[k]) + 1) * sizeof(char));
  strcpy(ans, s[k]);

  int t=0;
 
  while(t < k + 1) {
    free(s[t]);
    t++;
  }
  free(s);

  return ans;
}


int intal_max(char **arr, int n)
{
if(n==0)
    return -1;
int i=1;
int max=0;
while(i < n)
{
    int w=intal_compare(arr[i],arr[max]);
    if(w==1)
        max=i;
    i++;
}
    return max;
}


int intal_min(char **arr, int n)
{
if(n==0)
    return -1;
int i=1;
int min=0;
while(i < n)
{
    int w=intal_compare(arr[i],arr[min]);
    if(w==-1)
        min=i;
    i++;
}
    return min;
}


int intal_search(char **arr, int n, const char* key)
{
int u=0;
while(u < n)
{
    int w=intal_compare(arr[u],key);
        if(w==0)
           return u;
    u++;
}
    return -1;
}


int intal_binsearch(char **arr, int n, const char* key)
{
  int lowest = 0;
  int highest = n;
  int ans = -1;
  while (highest > lowest) {
    int middle_ele = lowest + (highest-lowest) / 2;
    int w=intal_compare(key,arr[middle_ele]);
    if (w==1) 
    {
      lowest = middle_ele + 1;
    } 
    else if (w==-1) 
    {
      highest = middle_ele;
    } 
    else 
    {
      ans = middle_ele;
      highest = middle_ele;
    }
  }
  return ans;
}



int part(char** input, int low_ele, int high_ele) {
  int u = low_ele - 1;
  char* pivot = input[high_ele];

  for(int v = low_ele; v < high_ele; ++v) {
    if(intal_compare(input[v], pivot) < 0) {
      ++u;
      char* temp_var = input[u];
      input[u] = input[v];
      input[v] = temp_var;
    }
  }

  char* temp_var = input[u + 1];
  input[u + 1] = input[high_ele];
  input[high_ele] = temp_var;

  return (u + 1);
}

void quick_sort(char** input, int low_ele, int high_ele) {
  if(low_ele < high_ele) {
    int pi = part(input, low_ele, high_ele);
    quick_sort(input, low_ele, pi - 1);
    quick_sort(input, pi + 1, high_ele);
  }
}

void intal_sort(char **arr, int n) {
  quick_sort(arr, 0, n - 1);
}


char* coin_row_problem(char **arr, int n) {
  char** u = (char**)malloc((n + 1) * sizeof(char*));
  u[0] = (char*)malloc(2 * sizeof(char));
  u[0][0] = '0';
  u[0][1] = '\0';

  int j=0;

  while(j < n) {
    u[j + 1] = (char*)malloc((strlen(arr[j]) + 1) * sizeof(char));
    strcpy(u[j + 1], arr[j]);
    j++;
  }

  for(int i = 2; i < n + 1; ++i) {
    char* ele = intal_add(arr[i -1], u[i - 2]);
    if(intal_compare(ele, u[i - 1]) > 0) {
      char* temporay_var = u[i];
      u[i] = ele;
      free(temporay_var);
    } else {
      free(u[i]);
      u[i] = (char*) malloc((strlen(u[i - 1]) + 1) * sizeof(char));
      strcpy(u[i], u[i - 1]);
      free(ele);
    }
  }

  char* ans = (char*)malloc((strlen(u[n]) + 1) * sizeof(char));
  strcpy(ans, u[n]);

  for(int i = 0; i < n + 1; ++i) {
    free(u[i]);
  }
  free(u);

  return ans;
}


char* intal_pow(char* intal1, unsigned int n) {
  if(n == 0) 
  {
    char* ans = (char*)malloc(2 * sizeof(char));
    ans[0] = '1';
    ans[1] = '\0';
    return ans;
  }

  char* ans = (char*)malloc((strlen(intal1) + 1) * sizeof(char));
  strcpy(ans, intal1);
  int i = 1; 

  while(i < n) 
  {
    char* arg = ans;
    ans = intal_multiply(ans, intal1);
    free(arg);
    i++;
  }

  return ans;
}