#include<bits/stdc++.h>
using namespace std;

unsigned char tape[300000];
 
// set the pointer to point at the left-most cell of the tape
unsigned char* ptr = tape;


stack<char> st;
void interpret(string code) {
    char current_char;
    int i;
    size_t loop;

    for (i = 0; i < code.size(); i++) {
        printf("code[%d]\n", i);
        printf("cuurent char %d\n", *ptr);
        current_char = code[i];
        if (current_char == '>') {
            ++ptr;
        } else if (current_char == '<') {
            --ptr;
        } else if (current_char == '+') {
            ++*ptr;
        } else if (current_char == '-') {
            --*ptr;
        } else if (current_char == '.' ) {
            printf("%c", *ptr);
        } else if (current_char == ',') {
            printf("tira de st sz %d\n", st.size());
            *ptr = st.top();
            st.pop();
        } else if (current_char == '[') {
            continue;
        } else if (current_char == ']' && *ptr) {
            loop = 1;
            while (loop > 0) {
                //printf("vai acessar i-1 %d\n", i-1);
                current_char = code[--i];
                if (current_char == '[') {
                    loop--;
                } else if (current_char == ']') {
                    loop++;
                }
            }
        }
    }
}


int main() {
    string code = " >,<>>,>,<[->-               >+<><<]+->>[-<<+>>]            <+-><><<<[-+->-<+-<+>]<          [->+<]><>>>>>><>++->>+->>         >>>+[>><>>>[-]<[-<>-+]<<>[-        +-]-++-+-<         [-]<><<>[+       ---+]<><<             <<+-<<<<>      -+<><<<>                 <+-<<[->     >>>>>>+                     >>>>>-+    >+<<<><            <          <><<<<<   <<<<]>[           ->>           >>><><>  ><>>+>>          >>>>+            <<<<<>< <<<<+-<           <<<]>             [->>>>> >><>+                    >>>>-                    +><>>                    +<<<<                    <<+-<                    <<<><<<<        -+><]     >>-++-+>+-+[<-]      <[->>    <>++-<<<]>>>>      [-<<<     +--+<<<<+>><>>>      >>>]>    [-<<-+<<<<<+<>>     +->>>     >>>]>[-<<<<><<<      ><<+>    >>>>>>]>>>>>><>>+    [-<<<     <+--+<><+-<<<<<      <[->>    +>>+<<<<]+->[->>+>>   +-+<<     <<]>[-<<+>>]>[-      <<+>>    ]+[[<>-]-++>[<-]<+-[   +--><     >><>-<<<]>>-+->      >>+>[    <-]<+-[-       >+>[-    <-]<[          >>[-<           <-+->    ]-<<[->         ><-     >+->-          +-<<<           <]]<]    >>-<<<           <      <+>[>          <<-]<           [>+->    [-+<<-                   >]<<[          <]]>-           +-]>>    >>><>>                   >><>+          ]-<<<           >+-<<    <>+>-                    ++[<-          ]<[-+           >>+[<    <<>->                    -+]<<          [>>>+           [<-+<    <->>]                    <<<[<          ]]]>-           ]>>>>    [-]<<                    <<<<<          -+<><           <<<<<    <[-]>                    >+>+[          <-]<[           ->>+<    ><<<]                    >+>[<          -]<[>           >[<<-    >]<<[                    <]]>-          [+>>>           >>>><    ++-++                    +++++          ++<<<           <<<+>    +-[<<>                   -]<[>          >[<<-           >]<<[    <]]>-[                   ++>[<          -]<[-           >>-<<    <]>>->           >      +>>+>          -[<-]           <[<<[    ->>>+<<         ><<     ]+->>          >>>+>           +[<><    -]<><[->       >+<<<    ]<<-<          ]<<<<           +>[<-    ]<[>>[<<->]<<[<]]>-]   >>+++          +++++[   ->     +++++    +<]>[-<<<<+>>>>]>>>   >>+><          >-+[<-]<[>>     [<<->    ]<<[<]]>-[++>[<-]    <[->>          -<<<]>>-<<<     <<<<<    +>+[<-]<[->>+<<     <]>>>          >>>>>+>[<-      ]<[>>    [<<->]<<[<]]>      -]<<[           -]<<<<<+>      [<-]<    [>>[<<->        ]<<[<            ]]>-]<<       [.<]!";
    for(int a=33;a<=126;a++){
        for(int b=33;b<=126;b++){
            for(int c=33;c<=126;c++){
                st.push(char(a)); 
                st.push(char(b));
                st.push(char(c));
                memset(tape, 0, sizeof(tape));
                printf("res[\"%c%c%c\"] = ", a, b, c);
                ptr = tape;
                interpret(code);
            }
        }
    }
    // outputs input 
    return 0; 
}
