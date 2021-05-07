# Construyamos el árbol:
#    6     
#   / \
#  1   9 
curl -X POST http://localhost:9080/addItem/6
curl -X POST http://localhost:9080/addItem/1
curl -X POST http://localhost:9080/addItem/9

# Guardar y crear un nuevo árbol
curl -X POST http://localhost:9080/newTree

# Construyamos el árbol:
#          5     
#      /     \
#   3           7 
#  / \         / \ 
# 1   4       6   9
#  \             /  \
#   2           8   10 

curl -X POST http://localhost:9080/addItem/5
curl -X POST http://localhost:9080/addItem/3
curl -X POST http://localhost:9080/addItem/7
curl -X POST http://localhost:9080/addItem/1
curl -X POST http://localhost:9080/addItem/4
curl -X POST http://localhost:9080/addItem/6
curl -X POST http://localhost:9080/addItem/9
curl -X POST http://localhost:9080/addItem/2
curl -X POST http://localhost:9080/addItem/8
curl -X POST http://localhost:9080/addItem/10

# Veamos el árbol
curl http://localhost:9080/seeTree

# Consultemos algunos ancestors
curl http://localhost:9080/commonAncestor/1,2 # debe mostrar 1
curl http://localhost:9080/commonAncestor/2,2 # debe mostrar 2
curl http://localhost:9080/commonAncestor/1,4 # debe mostrar 3
curl http://localhost:9080/commonAncestor/4,4 # debe mostrar 4
curl http://localhost:9080/commonAncestor/3,7 # debe mostrar 5
curl http://localhost:9080/commonAncestor/1,6 # debe mostrar 5
curl http://localhost:9080/commonAncestor/2,7 # debe mostrar 5
curl http://localhost:9080/commonAncestor/6,6 # debe mostrar 6
curl http://localhost:9080/commonAncestor/6,8 # debe mostrar 7
curl http://localhost:9080/commonAncestor/8,8 # debe mostrar 8
curl http://localhost:9080/commonAncestor/9,8 # debe mostrar 9
curl http://localhost:9080/commonAncestor/10,10 # debe mostrar 10
