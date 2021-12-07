int main() {
    int i = 0; // scope of outer i begins
    ++i; // outer i is in scope
    {
        int i = 1; // scope of inner i begins,
                   // scope of outer i pauses
        i = 42; // inner i is in scope
    } // block ends, scope of inner i ends,
      // scope of outer i resumes
} // block ends, scope of outer i ends
//int j = i; // error: i is not in scope
