#include "frame_password.h"
void PasswordFrame::createPasswordFrame(Cache& cache){
	username_entry = std::make_unique<QLineEdit>();
	password_entry = std::make_unique<QLineEdit>();
	label_name = std::make_unique<QLabel>("Username");
	label_password = std::make_unique<QLabel>("Password");
	save_button = std::make_unique<CustomButton>("Save Password");
	generate_button = std::make_unique<CustomButton>("Generate Password");
	connect(generate_button.get(),&QPushButton::clicked,this,&PasswordFrame::GeneratePassword);
	
	password_frame = std::make_shared<CustomFrame>();
	password_frame_layout = std::make_unique<QVBoxLayout>();
	password_frame_layout->addWidget(label_name.release());
	password_frame_layout->addWidget(username_entry.release());
	password_frame_layout->addWidget(label_password.release());
	password_frame_layout->addWidget(password_entry.release());
	password_frame_layout->addWidget(generate_button.release());
	password_frame_layout->addWidget(save_button.release());
	password_frame->setLayout(password_frame_layout.release());
	cache.cacheFrame("Password",password_frame);
}
void PasswordFrame::GeneratePassword(){
    QString to_append;
	int index;
	int selector;
	int max_char = 16;
	// Arrays come from characters.h
	QString password = ""; 
	srand(time(nullptr));
	// Employs a selector to randomly select one of four possible characters.
	// rand to randomly pick from arrays after selector. 
	for (int i = 0;i < max_char;i++) {
		selector = rand() % 4;
		
		if (selector == ID_NUMBERS) {
			to_append = QString::number(rand() % 10);
		}
		else if (selector == ID_LOWER_ALPHABETS) {
			index = rand() % 26;
			to_append = lower_alphabets[index];
		}
		else if (selector == ID_UPPER_ALPHABETS) {
			index = rand() % 26;
			to_append = upper_alphabets[index];
		}
		else if (selector == ID_SYMBOLS) {
			index = rand() % 22;
			to_append = symbols[index];
		}
		password.append(to_append);
	}
	
	password_entry->setText(password);
}
void PasswordFrame::cacheWidgets(){
	password_widget_cache["generate"] = generate_button.get();
	password_widget_cache["save"] = save_button.get();
	password_widget_cache["username_entry"] = username_entry.get();
	password_widget_cache["password_entry"] = password_entry.get();
	password_widget_cache["label_name"] = label_name.get();
	password_widget_cache["label_password"] = label_password.get();
}
