std::thread::id master_thread;
void some_core_part_of_algorithm() {
    if (std::this_thread::get_id() == master_thread) {					
         do_master_thread_work();
     }					
     do_common_work();					
}

void process_big_object(std::unique_ptr<big_object>);
std::unique_ptr<big_object> p(new big_object);
p->prepare_data(42);
std::thread t(process_big_object, std::move(p));

class X {
public:
    void do_lengthy_work();
};
X my_x;
std::thread t(&X::do_lengthy_work, &my_x);

class X {
public:
    void do_lengthy_work();
};
X my_x;
std::thread t(&X::do_lengthy_work,&my_x);

std::thread t(update_data_for_widget, w, std::ref(data)); 			

void update_data_for_widget(widget_id w, widget_data& data);
void oops_again(widget_id w) {
    widget_data data;
    std::thread t(update_data_for_widget, w, data);
    display_status();
    t.join();
    process_widget_data(data);					
}

void f(int i,std::string const& s);
void not_oops(int some_param) {
    char buffer[1024]; 
    sprintf(buffer,"%i",some_param); 
    std::thread t(f,3,std::string(buffer)); 
    t.detach();
} 

void f(int i,std::string const& s);
void oops(int some_param) {					
    char buffer[1024]; // local array on stack!
    sprintf(buffer, "%i",some_param);				
    std::thread t(f,3,buffer);
    t.detach();
}

void f(int i,std::string const& s);				
std::thread t(f, 3, "hello");

std::thread t(do_background_work);
t.detach();
assert(!t.joinable());

std::thread my_thread((background_task()));
std::thread my_thread{background_task()};	

void do_some_work();				
std::thread my_thread(do_some_work);


