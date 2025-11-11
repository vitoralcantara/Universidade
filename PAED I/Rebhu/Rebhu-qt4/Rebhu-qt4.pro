SOURCES += ../main.cpp \
 ../RebhuDefaults.cpp \
 ../RebhuMain.cpp \
 ../BitLib/BitArray.cpp \
 ../BitLib/BitFile.cpp \
 ../BWT/BlockSort.cpp \
 ../BWT/BurrowsWheeler.cpp \
 ../Huffman/Huffman.cpp \
 ../Huffman/HuffmanTree.cpp \
 ../RLE/Rle.cpp \
 ../rebhuMainWindow.cpp \
 ../rebhuAbout.cpp \
 ../rebhuProgressDialog.cpp
HEADERS += ../RebhuDefaults.h \
 ../RebhuMain.h \
 ../BitLib/BitArray.h \
 ../BitLib/BitFile.h \
 ../BST/BinarySearchTree.h \
 ../BWT/BlockSort.h \
 ../BWT/BurrowsWheeler.h \
 ../Huffman/Huffman.h \
 ../Huffman/HuffmanTree.h \
 ../PriorityQueue/PriorityQueue.h \
 ../RLE/Rle.h \
 ../rebhuMainWindow.h \
 ../rebhuAbout.h \
 ../rebhuProgressDialog.h
FORMS += ../Dialogs-qt4/rebhuMainWindow.ui ../Dialogs-qt4/about.ui ../Dialogs-qt4/rebhuProgressDialog.ui
CONFIG += warn_on release
TEMPLATE = app
INCLUDEPATH += ..
RESOURCES += ../Icons/resources.qrc
