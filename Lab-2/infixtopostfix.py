def priority(c):
  if c == '+' or c == '-':
    return 1
  elif c == '*' or c == '/':
    return 2
  elif c == '^':
    return 3
  else:
    return 0
  
def infixToPostFix(exp):
  stack=[]
  result =""
  for c in exp:
    if (c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z') or (c >= '0' and c <= '9'):
      result += c
    elif c == '(':
      stack.append(c)
    elif c == ')':
      while stack and stack[-1] != '(':
        result += stack.pop()
      stack.pop()
    else:
      while stack and priority(c) <= priority(stack[-1]):
        result += stack.pop()
      stack.append(c)
  while stack:
    result += stack.pop()
  return result

infix_exp = input("Enter an infix expression: ")
postfix_exp = infixToPostFix(infix_exp)
print(f"Postfix expression is {postfix_exp}")