def evaluate_postfix(postfix_exp):
    tokens=postfix_exp.split()
    stack=[]
    operator={"^","/","*","+","-"}
    for token in tokens:
        if token not in operator:
            stack.append(float(token))
        else:
            op1=stack.pop()
            op2=stack.pop()

            if token == '+':
                result=op2+op1
            elif token=='-':
                result=op2-op1
            elif token=='*':
                result=op2*op1
            elif token=='/':
                result=op2/op1
            elif token=='^':
                result=op2**op1
            stack.append(result)
    return stack[0]

            
            
inp=input("Enter a postfix ")
result =evaluate_postfix(inp)
print(f"Result is {result}")