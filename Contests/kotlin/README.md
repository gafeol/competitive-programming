# Using kotlin in programming competitions

Install kotlin.


To save time compiling and running kotlin code, add this function to your `.bash_aliases` file:

```bash
kt() {
    if [ -f "$1".kt ]; then
        kotlinc "$1".kt -include-runtime -d "$1".jar
        java -jar "$1".jar
    else 
        echo "File $1.kt not found!"
    fi
}
```

After this, to run any kotlin file (.kt) just run `kt <filename>`.
For instance, to run `A.kt`, one should simply run `kt A`.
