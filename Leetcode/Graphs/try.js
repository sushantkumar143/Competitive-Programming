let s = "abcba";
let n = s.length;
let flag = 1;

for(let i=0; i<s.length/2; i++) {
    if(s[i] != s[n-i-1]) {
        flag = 0;
        break;
    }
}

if(flag == 1) {console.log("It is palindrome")}
else {
    console.log("The string is not Palindrome")
}
