def infix_to_postfix(expression):
    precedence={'+':1,'-':1,'*':2,'/':2,'^':3}
    stack=[]
    postfix=[]
    for char in expression:
        if char.isalnum():
            postfix.append(char)
        elif char=='(':
            stack.append(char)
        elif char==')':
            while stack and stack[-1] !='(':
                postfix.append(stack.pop())
            stack.pop()
        elif char in precedence:
            while stack and stack[-1]!='(' and precedence[char]<= precedence[stack[-1]]:
                postfix.append(stack.pop())
            stack.append(char)
    while stack:
        postfix.append(stack.pop())
    return postfix
    
infix_expre="(A*B*(((m^X+D^Y)+E/Z)XF))"
print("Postfix:",infix_to_postfix(infix_expre))