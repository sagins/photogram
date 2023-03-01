#include "TestControl.h"
#include "TestView.h"
#include "Client.h"
#include <limits>

using namespace std;

void pressEnterToContinue();

void TestControl::launch(){
    //make a view, get input, launch the appropriate test
    TestView view;
    int choice = 5;

    while (choice!=0){
        view.showMenu(choice);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch(choice){
            case 1: photoTest(); break;
            case 2: albumTest(); break;
            case 3: albumArrayTest(); break;
            case 4: photoGramTest(); break;
            case 5: clientTest(); break;
        }

    }
}


int TestControl::photoTest(){
    Photo* photos[6];
    
    unordered_set<int> rphoto;    //random photos
    unordered_set<int> ralbum;   //random albums

    unordered_set<int>::iterator iphoto, ialb; //iterators for the sets

    int count = 0;

    ran(ralbum, 2, 5); // choose 2 out of 5 albums
    ran(rphoto, 3, 5); // choose 3 out of 5 photos
    
    for (ialb = ralbum.begin(); ialb != ralbum.end(); ++ialb){
        for (iphoto = rphoto.begin(); iphoto != rphoto.end(); ++iphoto){    
            photos[count++] = new Photo( photoTitles[*ialb][*iphoto], Date(), photoContent[*ialb][*iphoto]);
            cout<<endl<<"Adding "<<photoTitles[*ialb][*iphoto] <<endl;
        }

    }
    
    cout<<endl<<"Displaying photos:"<<endl<<endl;
    for (int i = 0; i < count; ++i){
        photos[i]->display(); cout<<endl;
        delete photos[i];
    }

    cout <<"**MANUAL MARK** If all photos are displayed (should be 6), 2 marks. If there was some mistake, 1 mark, for major mistakes, 0 marks"<<endl;
    return 0;
}
		
int TestControl::albumTest(){
    //unordered_set<int> rdescipt;  //random artist
    unordered_set<int> rphoto;    //random photo
    Album* albs[2];
    unordered_set<int>::iterator iphoto; //iterators for the sets

    
    ran(rphoto, 2, 5); // choose 2 out of 5 photos
    for (int i = 0; i < 2; ++i){
        int alb = ran(0,1);  // choose a random album
        cout<<endl<<"Adding Album  "<<albumTitles[alb]<<endl;
        albs[i] = new Album(albumTitles[alb], descriptions[alb]);
        for (iphoto = rphoto.begin(); iphoto != rphoto.end(); ++iphoto){ 
                cout<<"Adding Photo to Album: "<<albumTitles[alb]<<endl;
                albs[i]->addPhoto(new Photo(photoTitles[alb][*iphoto], Date(), photoContent[alb][*iphoto]));
        }
    }

    cout<<endl<<"Displaying albums with photos (should be 2 albums and 2 photos each album):"<<endl;
    for (int i = 0; i < 2; ++i){
        albs[i]->display();
    }

    cout<<endl<<"**MANUAL MARK** If all photos display (should be 2 albums and 2 photos each album, 4 photos total), 2 marks"<<endl;

    pressEnterToContinue();

    // Photo* photo = new Photo("The Backstreet Boys", "I Want It That Way", photoContent[0][0] );

    // cout<<endl<<"Attempting to add photos with wrong artist to albums:"<<endl;
    // photo->print();
    // for (int i = 0; i < 2; ++i){
    //     albs[i]->addPhoto(photo);
    // }

    // cout<<endl<<"Printing albums with photos:"<<endl;
    // for (int i = 0; i < 2; ++i){
    //     albs[i]->print();
    // }

    // cout<<endl<<"**MANUAL MARK** If there is no Backstreet Boys, 1 mark, otherwise 0"<<endl;

    for (int i = 0; i < 2; ++i){
        delete albs[i];
    }

    
    cout<<"Testing add Photo at index"<<endl;
    Album* album = new Album(albumTitles[0], descriptions[0]);
    Photo* photos[3];
    for (int i = 0; i < 3; ++i){
        photos[i] = new Photo(photoTitles[0][i], Date(), photoContent[0][i]);
    }
    cout<<endl<<"Adding photo at bad index"<<endl;
    album->addPhoto(2, photos[0]);
    album->display();
    cout<<"**MANUAL MARK** If photo "<< photoTitles[0][0] <<" did not print, 2 mark"<<endl;
    cout<<"(Should not be any photos in this album)"<<endl;
    pressEnterToContinue();
    cout<<endl<<"Adding 3 photos at good indices and displaying"<<endl;
    album->addPhoto(0, photos[0]);
    album->addPhoto(0, photos[1]);
    album->addPhoto(1, photos[2]);
    album->display();

    //pressEnterToContinue();

    int marks = 6;
    bool correct = true;

    
    cout<<"Checking photos were added in order:"<<endl;
    Photo* photo = album->getPhoto(0);
    if (photo != photos[1]){
        cout<<"Wrong photo at index 0"<<endl;
        correct = false;
    }
    photo = album->getPhoto(1);
    if (photo != photos[2]){
        cout<<"Wrong photo at index 1"<<endl;
        correct = false;
    }
    photo = album->getPhoto(2);
    if (photo != photos[0]){
        cout<<"Wrong photo at index 2"<<endl;
        correct = false;
    }

    if (!correct){
        marks -= 2;
    }else{
        cout<<"Photos were in correct order"<<endl;
    }
    pressEnterToContinue();
    correct = true;

    

    cout<<"Testing remove photo at index 1 (2 photos left):"<<endl;
    photo = album->removePhoto(1);
    album->display();
    photo = album->getPhoto(0);
    if (photo != photos[1]){
        cout<<"Wrong photo at index 0"<<endl;
        correct = false;
    }
    photo = album->getPhoto(1);
    if (photo != photos[0]){
        cout<<"Wrong photo at index 1"<<endl;
        correct = false;
    }

    if (!correct){
        marks -= 2;
    }else{
        cout<<"Photos were in correct order after remove at index 1"<<endl;
    }

    pressEnterToContinue();
    correct = true;

    cout<<"Testing remove photo at index 0 (1 photo left):"<<endl;
    album->removePhoto(0);
    album->display();
    photo = album->getPhoto(0);
    if (photo != photos[0]){
        cout<<"Wrong photo at index 0"<<endl;
        correct = false;
    }

    if (!correct){
        marks -= 1;
    }else{
        cout<<"Photos were in correct order after remove at index 0 (1 photo left)"<<endl;
    }

    pressEnterToContinue();
    correct = true;

    cout<<"Testing remove photo at index 1 (should not remove anything):"<<endl;
    if (album->removePhoto(1)!=NULL){
        cout<<"Remove at bad index should return NULL"<<endl;
        marks -= 1;
    }
    cout<<"Displaying album (should be 1 photo):"<<endl;
    album->display();
    photo = album->getPhoto(0);
    if (photo != photos[0]){
        cout<<"Wrong photo at index 0"<<endl;
        marks -= 1;
    }

    cout<<"Testing remove photo at index 0 (0 photos left):"<<endl;
    photo = album->removePhoto(0);
    if (photo != photos[0]){
        cout<<"Wrong photo at index 0"<<endl;
        marks -= 1;
    }
    cout<<"Printing album (should be 0 photos), if any photos print deduct 1 mark:"<<endl;
    album->display();

    pressEnterToContinue();

    cout<<"Testing remove photo at index 0 (should fail):"<<endl;
    photo = album->getPhoto(0);
    if (photo!=NULL){
        cout<<"***ERROR**** getPhoto returned a photo, should return NULL, printing photo"<<endl;
        photo->print();
        marks -= 1;
    }else{
        cout<<"No photo found at index 0"<<endl;
    }
   
    delete album;
    for (int i = 0; i < 3; ++i){
        delete photos[i];
    }
    cout<<"Marks earned: "<<(marks>0?marks:0)<<" out of 6, plus 4 manual marks (inspecting the print statements in the first 2 tests). Divide this mark by 2 for a mark out of 5."<<endl;
    return 0;
}
		
int TestControl::albumArrayTest(){
    int points = 0;

    unordered_set<int> ralb;  //random artist
    unordered_set<int> rphoto;    //random photo
    Album* albs[4];
    unordered_set<int>::iterator ialb, iphoto; //iterators for the sets

    ran(ralb, 4, 5);
    ran(rphoto, 2, 5); // choose 2 out of 5 photos
    int count = 0;
    for (ialb = ralb.begin(); ialb!= ralb.end(); ++ialb){
        albs[count] = new Album(albumTitles[*ialb], descriptions[*ialb]);
        for (iphoto = rphoto.begin(); iphoto != rphoto.end(); ++iphoto){ 
                albs[count]->addPhoto(new Photo(photoTitles[*ialb][*iphoto], Date(), photoContent[*ialb][*iphoto]));
        }
        ++count;
    }
    

    cout<<"Adding Albums to AlbumArray"<<endl;

    AlbumArray* aa = new AlbumArray();
    for (int i = 0; i < 4; ++i){
        cout<<"Adding: ";
        albs[i]->print();
        aa->add(albs[i]);
    }

    cout<<"AlbumArray size (should be 4): "<<aa->size()<<endl;

    if (aa->size() ==4){
        cout<<"Correct size, +1 mark"<<endl;
        points += 1;
    }

    pressEnterToContinue();

    for (int i = 0; i < aa->size(); ++i){
        aa->get(i)->print();
    }
    
    Album* alb;
    
    
    cout<<endl<<"Test get(title):   "<<endl<<endl;
    bool foundall = true;
    for (int i = 0; i < aa->size(); ++i){
        alb = aa->get(albs[i]->getTitle());
        if (alb != albs[i]){
            cout <<"Could not find "<<endl;
            albs[i]->print();
            foundall = false;
        }else{
            cout<<"Found "<<endl;
            alb->print();
        }
    }

    if (foundall){
        cout<<"Found all albums, +1 mark"<<endl<<endl;
        points += 1;
    }else{
        cout<<"Did not find all albums, 0 marks (out of 1)"<<endl;
    }

    pressEnterToContinue();
    alb = aa->get("TOP SECRET");
    if(alb!=NULL){
        cout<<"****ERROR**** Found non-existent TOP SECRET album, attempting to print:"<<endl;
        alb->print();
    }else{
        cout<<"Success: Did not find the (non-existent) TOP SECRET album, +1 marks"<<endl;
        points += 1;
    }
    
    cout<<endl<<"Test Album* get(int) (proper order): "<<endl<<endl;

    pressEnterToContinue();
    bool inorder = true;
    
    Album *a1, *a2;
    for (int i = 1; i < aa->size(); ++i){
        a1 = aa->get(i-1);
        a2 = aa->get(i);
        if (a1 == NULL){
            cout<<"Error, album at index "<<i-1<<" not found"<<endl;
            inorder = false;
        }
        if (a2 == NULL){
            cout<<"Error, album at index "<<i<<" not found"<<endl;
            inorder = false;
        }

        if (inorder && a2->lessThan(*a1)){
            a1->print();
            a2->print();
            inorder = false;
            cout<<endl<<"Previous two albums are out of order"<<endl;
        }
    }

    for (int i = 0; i < aa->size(); ++i){
        aa->get(i)->print();
    }

    cout<<endl<<(inorder ? "In correct order, +2 marks": "Not in correct order")<<endl;
    if (inorder){points+=2;}

    pressEnterToContinue();

    int num = ran(0,4);
    cout << "Removing "<<endl;
    albs[num]->print();
    alb = aa->remove(albs[num]->getTitle());
    if (alb!=albs[num]){
        cout<<"***ERROR*** Could not find the above album, deducting 1 mark"<<endl;
        points -= 1;
    }

    if (aa->size() != 3){
        cout<<"AlbumArray size error, should be 3, instead: "<<aa->size()<<endl;
    }else{
        cout<<"Size is correct after removal, +1 mark" <<endl;
        points += 1;
    }

    pressEnterToContinue();
    cout<<endl<<"Test proper order after remove: "<<endl<<endl;
    inorder = true;
    for (int i = 1; i < aa->size(); ++i){
        a1 = aa->get(i-1);
        a2 = aa->get(i);
        if (a2->lessThan(*a1)){
            a1->print();
            a2->print();
            inorder = false;
            cout<<endl<<"Previous two albums are out of order"<<endl;
        }
        if (albs[num]==a1 || albs[num]==a2){
            cout<<"Deleted album found"<<endl;
            inorder = false;
        }
    }

    for (int i = 0; i < aa->size(); ++i){
        aa->get(i)->print();
    }
    
    cout<<endl<<(inorder ? "In correct order": "Not in correct order")<<endl<<endl;
    if (inorder){cout<<"Delete successfull, +1 mark"<<endl; points += 1;}

    pressEnterToContinue();

    cout<<"Removing all albums from AlbumArray..."<<endl;
    while (aa->size()>0){
        alb = aa->remove(0);
        cout<<"Removed: "<<endl;
        alb->print();
    }

    cout<<"AlbumArray size (should be 0): "<<aa->size()<<endl;
    if (aa->size() == 0){
       cout<<"Success, +1 mark"<<endl;
        points += 1;
    }
    
    pressEnterToContinue();

    cout<<endl<<"Adding album back: "<<endl;
    albs[2]->print();
    pressEnterToContinue();
    aa->add(albs[2]);
    cout<<"Printing all albums (should be same album as above):"<<endl;
    for (int i = 0; i < aa->size(); ++i){
        a1 = aa->get(i);
        a1->print();
        if (a1 != albs[2]){
            cout<<"Wrong album added"<<endl;
        }else{
            cout<<"Delete all then add test passed, +2 marks"<<endl;
            points += 2;
        }
    }

    pressEnterToContinue();

    cout<<"Deleting AlbumArray..."<<endl;
    delete aa;
    cout<<"**MANUAL MARK** If an error occurs in the next step, student may have deleted Album with AlbumArray, deduct 4 marks"<<endl<<endl;

    pressEnterToContinue();
    cout<<"Deleting albums..."<<endl;
    for (int i = 0; i < 4; ++i){
        delete albs[i];
    }

    cout<<"All albums deleted"<<endl;
    cout<<"Marks earned: "<<points<<endl;
    cout<<"Check above for manual deductions. Divide marks earned minus the deduction by 2 for a mark out of 5"<<endl;

    return points;
}

int TestControl::photoGramTest(){
    int points = 5;
    PhotoGram photoGram;
    cout<<"Initializing with Albums and photos"<<endl;
    initialize(&photoGram);

    cout<<"Printing all albums (should be 5 albums) "<<endl<<endl;
    photoGram.printAlbums();
    cout<<"**MANUAL MARK** If all albums print (without photos) 1 mark, otherwise 0 marks"<<endl;

    pressEnterToContinue();

    cout<<endl<<"Displaying all albums (should be 5 albums, 5 photos each album): "<<endl;
    photoGram.displayAlbums();
    cout<<"**MANUAL MARK** If all (5) albums display 5 photos each, 1 mark, otherwise 0 marks"<<endl;

    pressEnterToContinue();

    cout<<endl<<"Testing find albums and photos..."<<endl;
    
    //Photo* photoTest = 
    
    Album* album;
    Photo* photo;
    for (int i = 0; i < 5; ++i){
        album = photoGram.downloadAlbum(albumTitles[i]);
        if (!album->equals(albumTitles[i])){
            cout <<"Album "<< albumTitles[i] <<" not found using function downloadAlbum, -1 point"<<endl;
            --points;
        }else{
            cout<<endl<<"Album "<<albumTitles[i]<<" found using function downloadAlbum, attempting to display all photos:"<<endl;
            pressEnterToContinue();
            for (int j = 0; j < 5; ++j){

                photo = photoGram.
                downloadPhoto(albumTitles[i], photoTitles[i][j]);

                if (photo==NULL||!photo->equals(photoTitles[i][j])){
                    cout << "Photo "<<photoTitles[i][j]<<" from "<<albumTitles[i]<<" not found, -1 point"<<endl;
                    --points;
                    pressEnterToContinue();
                }else{
                    cout<<"Photo found: "<<endl;
                    photo->display();
                }
            }
        }

    }


    

    int photoIndex = ran(0,5);
    int albumIndex = ran(0,5);
    cout <<endl<<"Testing removePhoto...removing photo "<<photoTitles[albumIndex][photoIndex]
         <<" from "<<albumTitles[albumIndex]<<endl;
    if (!photoGram.removePhoto(albumTitles[albumIndex], photoTitles[albumIndex][photoIndex])){
        cout << "Photo not found (or did you forget to return true?), -1 point"<<endl;
        --points;
    }else{
        cout<<"Photo successfully(?) removed, attempting to download:"<<endl;
        photo = photoGram.downloadPhoto(albumTitles[albumIndex], photoTitles[albumIndex][photoIndex]);
        if (photo!=NULL){
            cout << "Photo found after removal (or did you return true by accident?), -1 point, attempting to print..."<<endl;
            photo->print();
            --points;
        }else{
            cout<<photoTitles[albumIndex][photoIndex]<<" successfully removed"<<endl<<endl;;
        }
    }

    pressEnterToContinue();

    albumIndex = ran(0,5);
    cout <<"Testing removeAlbum...removing album "<<albumTitles[albumIndex]<<endl;
    if (!photoGram.removeAlbum(albumTitles[albumIndex])){
        cout << "Album not found (or did you forget to return true?), -1 point"<<endl;
        --points;
    }else{
        cout<<"Album successfully(?) removed, attempting to download:"<<endl;
        album = photoGram.downloadAlbum(albumTitles[albumIndex]);
        if (album!= NULL){
            cout << "Album found after removal (or did you return true by accident?), -1 point, attempting to print..."<<endl;
            album->print();
            --points;
        }else{
            cout<<"Album "<<albumTitles[albumIndex]<<" successfully removed"<<endl;
        }
    }
    cout<<endl<<"Points earned: "<<(points>0?points:0)<<" out of 7\n-add 1 if all albums printed correctly in the first test\n-add 1 if all albums and photos printed correctly in the second test"<<endl;
    return (points>0?points:0);
}


int TestControl::clientTest(){
    int points = 5;
    PhotoGram photoGram;
    Client client;

    initialize(&photoGram);

    int photoIndex = ran(0,5);
    int artistIndex = ran(0,3);
    int albumIndex = ran(0,2);
    cout <<"Testing display online, Photo "<<photoTitles[albumIndex][photoIndex]
         <<" from "<<albumTitles[albumIndex]<<endl<<endl;
    if (!client.displayOnlinePhoto(&photoGram, albumTitles[albumIndex], photoTitles[albumIndex][photoIndex])){
        cout << "Display online unsuccessful (or did you forget to return true?), -1 point"<<endl;
        --points;
    }

    pressEnterToContinue();

    cout <<"Testing download...downloading Album "<<albumTitles[albumIndex]<<endl<<endl;

    if(!client.downloadAlbum(&photoGram, albumTitles[albumIndex])){
        cout << "Download unsuccessful (or did you forget to return true?), -3 points, test aborted."<<endl;
        points-=3;
        cout<<endl<<"Marks earned: "<<(points>0?points:0)<<" out of 5"<<endl;
        return points;
    }

    pressEnterToContinue();
    

    cout<<endl<<"Testing displayLocal photo "<<photoTitles[albumIndex][photoIndex]
         <<" from "<<albumTitles[albumIndex]<<endl<<endl;
    cout<<"i.e., displaying the copy of photo stored in Client"<<endl;
    if (!client.displayLocalPhoto(albumTitles[albumIndex], photoTitles[albumIndex][photoIndex])){
        cout << "displayLocalPhoto unsuccessful (or did you forget to return true?), -1 mark"<<endl;
        --points;
    }

    cout<<endl<<"Deleting original album from PhotoGram, then testing displayLocal (from Client) again"<<endl<<endl;
    pressEnterToContinue();
    if(!photoGram.removeAlbum(albumTitles[albumIndex])){
        cout<<"Remove album failed (or did you forget to return true?), -2 marks, test aborted."<<endl;
        points-=2;
        cout<<endl<<"Marks earned: "<<(points>0?points:0)<<" out of 5"<<endl;
        return points;
    }


    if (!client.displayLocalPhoto(albumTitles[albumIndex], photoTitles[albumIndex][photoIndex])){
        cout << "Display Local unsuccessful (or did you forget to return true?), -1 point"<<endl;
        --points;
    }else{

        cout<<"Success! (Photo should be displayed.)"<<endl<<endl;
    }
    pressEnterToContinue();

    cout<<"**MANUAL MARK** Printing all albums from local memory, no photos (should be 1 album):"<<endl;
    client.printLocalAlbums();
    pressEnterToContinue();
   
    client.displayLocalAlbums();
    cout<<endl<<"**MANUAL MARK** Displaying all photos from local memory (should be 1 album, 5 photos): "<<endl;
    pressEnterToContinue();
    cout<<"Deduct 1 mark for each print and display function (immediately before this line) that does not work"<<endl;
    cout<<endl<<"Marks earned: "<<(points>0?points:0)<<" out of 5"<<endl;
    return points;

}

void TestControl::initialize(PhotoGram* photoGram){
    // unordered_set<int> rphoto;    //random photo
    // unordered_set<int>::iterator iphoto; //iterators for the sets

    // ran(rphoto, 2, 5); // choose 2 out of 5 photos


    for (int i = 0; i < 5; ++i){
        photoGram->addAlbum(albumTitles[i], descriptions[i]);
        //photo loop
        for (int j = 0; j < 5; ++j){
            photoGram->addPhoto(albumTitles[i], Photo(photoTitles[i][j], Date(),photoContent[i][j]));
        }
        // for (iphoto = rphoto.begin(); iphoto != rphoto.end(); ++iphoto){ 
        //     photoGram->addPhoto(albumTitles[i], Photo(photoTitles[i][*iphoto], Date(),photoContent[i][*iphoto]));
        // }
    }

}

// s is the set to store count random numbers from 0 to range - 1
void TestControl::ran(unordered_set<int>& s, int count, int range){
    const int range_from  = 0;
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  distr(range_from, range-1);

    while (s.size() < count){
        s.insert(distr(generator));
    }
}

// generate and return a single random number in the range range_from to range_to - 1
int TestControl::ran(int range_from, int range_to){
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  distr(range_from, range_to-1);
    return distr(generator);
}

void pressEnterToContinue(){
    cout << "Press enter to continue..."<<endl;
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    char c = cin.get();
    while ( c != '\n') { 
        c = cin.get();
    }
}


// random titles
const string TestControl::albumTitles[5] = {"Animals", "Friends", "Travel", "Family", "Selfies"};

const string TestControl::descriptions[5] = {"Animals from an African safari", "Friends in low places", "My trips to Cornwall", "Friends and fellow students", "Might delete later"};

const string TestControl::photoTitles[5][5] =
{"Lion", "Lion 2", "Fishbowl", "Alien", "Castle", "Love", "Anonymous", "Games","Music","Welcome","Monkey", "Stranger","Ant","Turtle","Smile","Crab","City","Apple","Pig","Dog","Helicopter","Unlock","Santa's Sleigh", "Guitar","Whale"};

const string TestControl::photoContent[5][5] = {
R"(
 ▄▀▀▀▀▀───▄█▀▀▀█▄
▐▄▄▄▄▄▄▄▄██▌▀▄▀▐██
▐▒▒▒▒▒▒▒▒███▌▀▐███
 ▌▒▓▒▒▒▒▓▒██▌▀▐██
 ▌▓▐▀▀▀▀▌▓─▀▀▀▀▀)",

R"(
┼┼┼┼┼┼┼┼▓▓▓▓┼┼┼
┼╔═▒▒▒▒▓▄░░▄▓┼┼
┼▀┼▒▒▒▓▓▒──▒▓▓┼
┼┼┼▒▌▒▐┼▓▓▓▓┼┼┼)",

R"(
─▀▀▌───────▐▀▀
─▄▀░◌░░░░░░░▀▄
▐░░◌░▄▀██▄█░░░▌
▐░░░▀████▀▄░░░▌
═▀▄▄▄▄▄▄▄▄▄▄▄▀═
)",

R"(
▒▒▄▀▀▀▀▀▄▒▒▒▒▒▄▄▄▄▄▒▒▒
▒▐░▄░░░▄░▌▒▒▄█▄█▄█▄█▄▒
▒▐░▀▀░▀▀░▌▒▒▒▒▒░░░▒▒▒▒
▒▒▀▄░═░▄▀▒▒▒▒▒▒░░░▒▒▒▒
▒▒▐░▀▄▀░▌▒▒▒▒▒▒░░░▒▒▒▒
)",
R"(
─────────█▄██▄█
█▄█▄█▄█▄█▐█┼██▌█▄█▄█▄█▄█
███┼█████▐████▌█████┼███
█████████▐████▌█████████
)",
R"(
█───▄▀▀▀▀▄─▐█▌▐█▌▐██
█──▐▄▄────▌─█▌▐█─▐▌─
█──▐█▀█─▀─▌─█▌▐█─▐██
█──▐████▄▄▌─▐▌▐▌─▐▌─
███─▀████▀───██──▐██
)",
R"(
─────█─▄▀█──█▀▄─█─────
────▐▌──────────▐▌────
────█▌▀▄──▄▄──▄▀▐█────
───▐██──▀▀──▀▀──██▌───
──▄████▄──▐▌──▄████▄──
)",
R"(
─▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄
█░░░█░░░░░░░░░░▄▄░██░█
█░▀▀█▀▀░▄▀░▄▀░░▀▀░▄▄░█
█░░░▀░░░▄▄▄▄▄░░██░▀▀░█
─▀▄▄▄▄▄▀─────▀▄▄▄▄▄▄▀
)",
R"(
║░█░█░║░█░█░█░║░█░█░║
║░█░█░║░█░█░█░║░█░█░║
║░║░║░║░║░║░║░║░║░║░║
╚═╩═╩═╩═╩═╩═╩═╩═╩═╩═╝
)",
R"(
█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█
█░░╦─╦╔╗╦─╔╗╔╗╔╦╗╔╗░░█
█░░║║║╠─║─║─║║║║║╠─░░█
█░░╚╩╝╚╝╚╝╚╝╚╝╩─╩╚╝░░█
█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█

)",
R"(
───▄██▄─────────────▄▄
──█████▄▄▄▄───────▄▀
────▀██▀▀████▄───▄▀
───▄█▀▄██▄████▄─▄█
▄▄█▀▄▄█─▀████▀██▀
)",
R"(
█▓▒▓█▀██▀█▄░░▄█▀██▀█▓▒▓█
█▓▒░▀▄▄▄▄▄█░░█▄▄▄▄▄▀░▒▓█
█▓▓▒░░░░░▒▓░░▓▒░░░░░▒▓▓█
)",
R"(
──▄──▄────▄▀
───▀▄─█─▄▀▄▄▄
▄██▄████▄██▄▀█▄
─▀▀─█▀█▀▄▀███▀
──▄▄▀─█──▀▄▄
)",
R"(
─▄▀▀▀▄────▄▀█▀▀█▄
▄▀─▀─▀▄▄▀█▄▀─▄▀─▄▀▄
█▄▀█───█─█▄▄▀─▄▀─▄▀▄
──█▄▄▀▀█▄─▀▀▀▀▀▀▀─▄█
─────▄████▀▀▀▀████─▀▄
)",
R"(
╔══╗░░░░╔╦╗░░╔═════╗
║╚═╬════╬╣╠═╗║░▀░▀░║
╠═╗║╔╗╔╗║║║╩╣║╚═══╝║
╚══╩╝╚╝╚╩╩╩═╝╚═════╝
)",
R"(
░░▄█▀▀▀░░░░░░░░▀▀▀█▄
▄███▄▄░░▀▄██▄▀░░▄▄███▄
▀██▄▄▄▄████████▄▄▄▄██▀
░░▄▄▄▄██████████▄▄▄▄
░▐▐▀▐▀░▀██████▀░▀▌▀▌▌
)",
R"(
▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
▒▒▄▄▄▒▒▒█▒▒▒▒▄▒▒▒▒▒▒▒▒
▒█▀█▀█▒█▀█▒▒█▀█▒▄███▄▒
░█▀█▀█░█▀██░█▀█░█▄█▄█░
░█▀█▀█░█▀████▀█░█▄█▄█░
████████▀█████████████
)",
R"(
┊┊┊┊┊┊┊╱▏┊┊┊┊┊┊┊
┊┊┊┊┊┊▕╱┊┊┊┊┊┊┊┊
┊┊┊╱▔▔╲┊╱▔▔╲┊┊┊┊
┊┊▕┈┈┈┈▔┈┈┈╱┊┊┊┊
┊┊▕┈┈┈┈┈┈┈┈╲┊┊┊┊
┊┊┊╲┈┈┈┈┈┈┈╱┊┊┊┊
┊┊┊┊╲▂▂▂▂▂╱┊┊┊┊┊
)",
R"(
▂╱▔▔╲╱▔▔▔▔╲╱▔▔╲▂
╲┈▔╲┊╭╮┈┈╭╮┊╱▔┈╱
┊▔╲╱▏┈╱▔▔╲┈▕╲╱▔┊
┊┊┊┃┈┈▏┃┃▕┈┈┃┊┊┊
┊┊┊▏╲┈╲▂▂╱┈╱▕┊┊┊
)",
R"(
╥━━━━━━━━╭━━╮━━┳
╢╭╮╭━━━━━┫┃▋▋━▅┣
╢┃╰┫┈┈┈┈┈┃┃┈┈╰┫┣
╢╰━┫┈┈┈┈┈╰╯╰┳━╯┣
╢┊┊┃┏┳┳━━┓┏┳┫┊┊┣
╨━━┗┛┗┛━━┗┛┗┛━━┻
)",
R"(
▀▀▀▀█▀▀▀▀
─▄▀█▀▀█──────▄
█▄▄█▄▄██████▀
▀▀█▀▀▀█▀▀
─▀▀▀▀▀▀▀
)",
R"(
──▄▀▀▀▄───────────────
──█───█───────────────
─███████─────────▄▀▀▄─
░██─▀─██░░█▀█▀▀▀▀█░░█░
░███▄███░░▀░▀░░░░░▀▀░░
)",
R"(
░╔╔╩╩╝
▄██▄
░░██████▄░░░░░░▄▄▄▄▄▄█
░░█▀█▀█▀█░░▄░▄████████
░▄▌▄▌▄▌▄▌░▀▄▄▄▄█▄▄▄▄█▄
)",
R"(
░▄▀▀▀▀▄░░▄▄
█░░░░░░▀▀░░█░░░░░░▄░▄
█░║░░░░██░████████████ 
█░░░░░░▄▄░░█░░░░░░▀░▀
░▀▄▄▄▄▀░░▀▀
)",
R"(
─────▀▄▀─────▄─────▄
──▄███████▄──▀██▄██▀
▄█████▀█████▄──▄█
███████▀████████▀
─▄▄▄▄▄▄███████▀
)"
};

