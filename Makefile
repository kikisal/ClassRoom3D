# build the static library

ClassRoom.exe: ./bin/ClassRoomApp.cc ./bin/classroomwin32.cc ./out/libs/librenderer_static.a
	g++ -I. ./bin/ClassRoomApp.cc ./bin/classroomwin32.cc -std=c++20 -L./out/libs -lrenderer_static -o ./out/bin/ClassRoom.exe
	cls
	.\out\bin\ClassRoom.exe

./out/libs/librenderer_static.a: modules/types.a modules/logger.a modules/base.a
	del .\out\libs\librenderer_static.a
	ar -rcT out/libs/librenderer_static.a ./modules/types.a ./modules/logger.a ./modules/base.a

modules/types.a: ./types/StringStream.cc
	g++ -I. ./types/StringStream.cc -c -o ./modules/objs/types/StringStream.o -std=c++20
	ar -r ./modules/types.a ./modules/objs/types/StringStream.o
modules/logger.a: ./logger/Debugger.cc
	g++ -I. ./logger/Debugger.cc -c -o ./modules/objs/logger/Debugger.o -std=c++20
	ar -r ./modules/logger.a ./modules/objs/logger/Debugger.o
modules/base.a: ./base/app.cc
	g++ -I. ./base/app.cc -c -o ./modules/objs/base/app.o -std=c++20
	ar -r ./modules/base.a ./modules/objs/base/app.o