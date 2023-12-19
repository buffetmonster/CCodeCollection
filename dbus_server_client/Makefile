
CFLAGS += -I/usr/include/dbus-1.0 -I/usr/lib/x86_64-linux-gnu/dbus-1.0/include
#CFLAGS += -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include
#LDFLAGS += -lglib-2.0 -ldbus-glib-1
LDFLAGS += -ldbus-1
#LDFLAGS+=-ldbus

all: dbus-server dbus-client

dbus-server:
	#gcc dbus-server.o -o dbus-server `pkg-config --libs dbus-1`
	#or
	gcc dbus-server.c -o dbus-server $(CFLAGS) $(LDFLAGS)

dbus-client:
	#gcc dbus-client.o -o dbus-client `pkg-config --libs dbus-1`
	#or
	gcc dbus-client.c -o dbus-client $(CFLAGS) $(LDFLAGS)

clean:
	rm -f *~ *.o  dbus-server dbus-client
