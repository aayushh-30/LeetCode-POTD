// Match remaining open brackets with unlocked characters
while (!openBrackets.empty() && !unlocked.empty() &&
       openBrackets.top() < unlocked.top()) {
    openBrackets.pop();
    unlocked.pop();
}