from Nodo import  *


VIOLET = "#ff31ff"
GREEN = "#02ff14"

class Trie(object ):
    def __init__( self ):
        self.m_pRoot = Nodo('#')
        self.nroWords = 0
        self.nroLetters = 0
        self.size = 0
	
    def addWord(self, word):
        self.nroWords = self.nroWords + 1
        self.nroLetters = self.nroLetters + len(word)
        self.size = self.size + self.m_pRoot.addWord(word)
        return True


   # Crea el diagrama con graphviz
    def printTrie(self, filename, render):
        from graphviz import Digraph
        from queue import Queue
        printTrie = Digraph(format='png')   
        printTrie.attr('node', fixedsize='true')
        printTrie.attr('node', shape='Mrecord',fillcolor=GREEN,style='filled')
        printTrie.attr('edge', arrowsize='0.5')
        i = 0
        printTrie.node(str(i), self.m_pRoot.getValueState())

        treeQueue = Queue()
        treeQueue.put((self.m_pRoot, i))

        while  not treeQueue.empty():

            nodo, indexFather = treeQueue.get()

            for child in nodo.getChildren():
                #print('parent: ', node.getValue(), indexFather)
                i += 1
                #print('child: ', child.getValue(), i)
                if child.isEndOfWord():
                    printTrie.attr('node', shape='diamond', style='filled', fillcolor=VIOLET)
                    printTrie.node(str(i), child.getValueState() )
                    printTrie.attr('node', shape='Mrecord', fillcolor='white')
                else:
                    printTrie.node(str(i), child.getValueState()) 
                printTrie.edge(str(indexFather), str(i),label=child.getValueState())
                treeQueue.put((child, i))

        file = open(filename + '.dot', 'w')
        file.write(printTrie.source)
        # print(printTrie.source)
        if render:
            printTrie.render(filename , view=True)
        file.close()
    

if __name__=='__main__':

    trie = Trie()

    # trie.addWord('apple')
    # trie.addWord('Apple')
    # trie.addWord('apples')
    # trie.addWord('banana')
    # trie.addWord('applet')

    trie.addWord('car')
    trie.addWord('cart')
    trie.addWord('cat')
    trie.addWord('pat')
    trie.addWord('pay')
    trie.addWord('play')
    trie.addWord('rat')
    trie.addWord('ray')
    trie.addWord('sat')
    trie.addWord('say')
    trie.addWord('stay')

    print()
  
    trie.printTrie('Trie', True)
