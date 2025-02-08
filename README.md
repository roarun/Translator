## **Translator Application**
### **Description**
This project is a **Translator Application** that utilizes a **Binary Search Tree (BST)** to store and manage a dictionary of word translations. The application allows users to:
- **Add** word translations to the dictionary.  
- **Search** for a translation by entering an English word.  
- **Display** all stored translations in sorted order.  

It includes **exception handling** to ensure robustness when handling duplicate words, missing entries, and memory allocation failures.

---

### **Features**
- **Binary Search Tree (BST) Implementation:** Stores word pairs efficiently for fast retrieval.  
- **Exception Handling:** Prevents duplicate entries, handles missing translations, and ensures memory safety.  
- **Makefile Support:** Automates compilation of multiple C++ source files.  
- **Command-Line Interaction:** Reads input from a file and allows user queries via terminal.  

---

### **How It Works**
1. The program reads a text file containing word translations in the format:  
   ```
   word:translation
   ```
   Example (`myDataFile.txt`):  
   ```
   pizza:pizza
   house:casa
   dog:perro
   apple:manzana
   ```

2. The words are **stored in a BST**, preventing duplicates and allowing efficient retrieval.  

3. Users can **input a word**, and the program will:
   - Return the translated word if it exists.
   - Display "***Not Found!***" if the word is missing.  
   - Display the entire dictionary when prompted.

---

### **Project Structure**
📂 **Project Files:**
- `Translator.cpp` → Main driver for the application.  
- `WordPair.h / WordPair.cpp` → Defines word-pair objects with overloaded operators for BST comparisons.  
- `BST.h / BST.cpp` → Implements a Binary Search Tree for dictionary storage.  
- `Dictionary.h / Dictionary.cpp` → Wrapper class for managing the BST-based dictionary.  
- `makefile` → Automates compilation.  
- `myDataFile.txt` → Sample dataset of word translations.  

📂 **Exception Handling Files:**
- `ElementAlreadyExistsException.h / .cpp` → Handles duplicate entries.  
- `ElementDoesNotExistException.h / .cpp` → Handles missing entries.  
- `EmptyDataCollectionException.h / .cpp` → Handles cases where the dictionary is empty.  
- `UnableToInsertException.h / .cpp` → Handles memory allocation failures.  

---

### **Compilation & Execution**
#### **To Compile:**
Run the following command to build the project using the **Makefile**:
```bash
make
```

#### **To Run:**
Provide a **data file** as input:
```bash
./Translator myDataFile.txt
```
Then, **enter a word** to translate or type `"display"` to view all stored translations.

---

### **Example Usage**
**Input:**
```bash
house
tree
display
```
**Output:**
```
house:casa
***Not Found!***
apple:manzana
dog:perro
house:casa
pizza:pizza
```

---

### **Future Improvements**
- Add support for **multiple languages**.  
- Implement **graphical user interface (GUI)** for better user experience.  
- Optimize BST operations for better performance with large datasets.  

---

Let me know if you'd like any modifications before finalizing! 🚀
