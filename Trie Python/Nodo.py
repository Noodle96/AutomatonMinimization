class Nodo(object ):   

    def __init__(self, value):
        self.endOfWord = False
        self.valueState=value
        self.prefix_count = 0
        self.children = []

     #Retorna un string con el atributo deseado mas no el objeto
    def __str__(self):
        return str(self.valueState)
    
    def isEndOfWord(self):
        return self.endOfWord

    # Establece el valor para endOfWord
    def setEndOfWord(self, T_or_F):
        self.endOfWord = T_or_F

    def setValueState(self, value):
        self.valueState = value

    def getValueState(self):
        return self.valueState
    
    # Obtiene  children
    def getChildren(self):
        return self.children
    # Agrega hijo
    def add_child(self, child):
        self.children.append(child)
    
    def addWord(self, word):
        size_increment = 0
        if word == '':
            self.setEndOfWord(True)
            return size_increment  
        result = None
        for child in self.children:
            # print("self.children",child)
            if child.valueState == word[0]:
                result = child
                return size_increment + result.addWord(word[1:])
        if result == None:
            new_child = Nodo(word[0])
            self.add_child(new_child)
            size_increment = size_increment + 1
            return size_increment + new_child.addWord(word[1:])
        return size_increment
