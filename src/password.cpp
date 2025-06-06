/*
   MIT License
   Copyright (c) 2025 Vasu Dhall(Speedforce1230)
   Please retain this copyright notice when using or modifying this project.
*/


#include "frame_password.h"
#include "button.h"
#include "entry.h"
#include "cache.h"
#include "characters.h"
void PasswordFrame::createPasswordFrame(Cache& cache) {
	// IMPORTANT!! This is strictly to cache the created frame, 
	// if you want to use it, call cache.getFrame and pass the correct key in your file.
	initWidgets(cache);
	password_frame = std::make_shared<CustomFrame>();
	password_frame_layout = returnFrameLayout();
	password_frame->setLayout(password_frame_layout.get());
	cacheWidgets(cache);
}

void PasswordFrame::initWidgets(Cache& cache) {
	// Initializing widgets and connecting.
	// IMPORTANT!!
	// if you want to connect a outside function to a button or anything else,
	// use the desired cache.getXXX method to attach it. Don't directly include anything into here
	// I am sick of circular includes.
	username_entry = std::make_shared<CustomLineEntry>(cache);
	password_entry = std::make_shared<CustomLineEntry>(cache);
	label_name = std::make_shared<QLabel>("Username");
	label_password = std::make_shared<QLabel>("Password");
	save_button = std::make_shared<CustomButton>("Save Password",cache);
	back_button = std::make_shared<CustomButton>("Back",cache);
	generate_button = std::make_shared<CustomButton>("Generate Password",cache);
}
unique_ptr<QBoxLayout> PasswordFrame::returnFrameLayout() {
	// creates a top to bottom layout and returns it.
	// Adds spacers at the top and bottom to center all widgets except the back button.
	QSpacerItem* top_spacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
	QSpacerItem* bottom_spacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
	unique_ptr<QBoxLayout> layout = std::make_unique<QVBoxLayout>();
	layout->addWidget(back_button.get(), 0, Qt::AlignLeft);
	layout->addSpacerItem(top_spacer);
	layout->addWidget(label_name.get(), 0, Qt::AlignCenter);
	layout->addWidget(username_entry.get(), 0,Qt::AlignHCenter);
	layout->addWidget(label_password.get(), 0, Qt::AlignCenter);
	layout->addWidget(password_entry.get(), 0,Qt::AlignHCenter);
	layout->addWidget(generate_button.get(),0,Qt::AlignCenter);
	layout->addWidget(save_button.get(), 0, Qt::AlignCenter);
	layout->addSpacerItem(bottom_spacer);
	return std::move(layout);
}

QString PasswordFrame::generatePassword(){
    QString to_append;
	int index;
	int selector;
	int max_char = 16;
	// Arrays come from characters.h
	QString password = ""; 
	srand(time(nullptr));
	// Employs a selector to randomly select one of four possible values.
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
	return password;
}
void PasswordFrame::setPassword(){
	QString set_password = generatePassword();
	password_entry->setText(set_password);
}
void PasswordFrame::cacheWidgets(Cache& cache){
	// The cache is unordered so don't worry about the order you cache your widgets in. Be careful with the keys!
	cache.cacheFrame("Password", password_frame);
	cache.cacheButton("generateButton", generate_button);
	cache.cacheButton("saveButton", save_button);
	cache.cacheButton("back", back_button);
	cache.cacheEntry("username_entry", username_entry);
	cache.cacheEntry("password_entry", password_entry);
}	
