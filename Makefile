CC=g++
FLAG=-Wall -Werror
OBJ=department.o emis.o employee.o main.o manager.o manager_ctrl_impl.o manager_mode_impl.o manager_view_impl.o service_ctrl_impl.o service_mode_impl.o service_view_impl.o tools.o
BIN=EIMS

all:$(OBJ)
	$(CC) $(OBJ) -o $(BIN) && ./$(BIN)

main.o:main.cpp tools.cpp tools.h emis.cpp emis.h manager.cpp manager.h employee.cpp employee.h department.cpp department.h
	$(CC) -c $(FLAG) main.cpp -o main.o
department.o:department.cpp department.h tools.cpp tools.h
	$(CC) -c $(FLAG) department.cpp -o department.o
emis.o:emis.cpp emis.h
	$(CC) -c $(FLAG) emis.cpp -o emis.o
employee.o:employee.cpp employee.h tools.cpp tools.h
	$(CC) -c $(FLAG) employee.cpp -o employee.o
manager.o:manager.cpp manager.h tools.cpp tools.h
	$(CC) -c $(FLAG) manager.cpp -o manager.o
manager_ctrl_impl.o:manager_ctrl_impl.cpp manager_ctrl_impl.h manager_ctrl.h manager_mode.h manager.cpp manager.h
	$(CC) -c $(FLAG) manager_ctrl_impl.cpp -o manager_ctrl_impl.o
manager_mode_impl.o:manager_mode_impl.cpp manager_mode_impl.h manager_mode.h manager.cpp manager.h
	$(CC) -c $(FLAG) manager_mode_impl.cpp -o manager_mode_impl.o
manager_view_impl.o:manager_view_impl.cpp manager_view_impl.h manager_view.h manager_ctrl.h manager.cpp manager.h
	$(CC) -c $(FLAG) manager_view_impl.cpp -o manager_view_impl.o
service_ctrl_impl.o:service_ctrl_impl.cpp service_ctrl_impl.h service_ctrl.h service_mode.h department.cpp department.h employee.cpp employee.h
	$(CC) -c $(FLAG) service_ctrl_impl.cpp -o service_ctrl_impl.o
service_mode_impl.o:service_mode_impl.cpp service_mode_impl.h service_mode.h department.cpp department.h employee.cpp employee.h
	$(CC) -c $(FLAG) service_mode_impl.cpp -o service_mode_impl.o
service_view_impl.o:service_view_impl.cpp service_view_impl.h service_view.h service_ctrl.h department.cpp department.h employee.cpp employee.h
	$(CC) -c $(FLAG) service_view_impl.cpp -o service_view_impl.o
tools.o:tools.cpp tools.h emis.cpp emis.h
	$(CC) -c $(FLAG) tools.cpp -o tools.o

clean:
	rm -rf *~ *.h.gch
	rm -rf $(OBJ) $(BIN)
