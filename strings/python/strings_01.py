def solveIndex(string):
    # ()[;;dll{}]
    condition = 0
    for i in range(len(string_input)):
        if string_input[i] == '[' or string_input[i] == '(' or string_input[i] == '{':
            condition += 1
        if string_input[i] == ')' or string_input[i] == ']' or string_input[i] == '}':
            condition -= 1
        if condition < 0:
            return False
    return True


should_try = True
while should_try:
    string_input = input("Enter a string: ").strip()
    print(solveIndex(string_input))
    should_try = (input("Should we try again? y/n").lower().strip() == "y")