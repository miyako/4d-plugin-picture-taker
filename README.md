# 4d-plugin-picture-taker

Simple picture taker panel for macOS

4D implementation of [IKPictureTaker](https://developer.apple.com/documentation/quartz/ikpicturetaker?language=objc)

### Platform

| carbon | cocoa | win32 | win64 |
|:------:|:-----:|:---------:|:---------:|
|<img src="https://cloud.githubusercontent.com/assets/1725068/22371562/1b091f0a-e4db-11e6-8458-8653954a7cce.png" width="24" height="24" />|<img src="https://cloud.githubusercontent.com/assets/1725068/22371562/1b091f0a-e4db-11e6-8458-8653954a7cce.png" width="24" height="24" />|||

### Version

<img src="https://cloud.githubusercontent.com/assets/1725068/18940649/21945000-8645-11e6-86ed-4a0f800e5a73.png" width="32" height="32" /> <img src="https://cloud.githubusercontent.com/assets/1725068/18940648/2192ddba-8645-11e6-864d-6d5692d55717.png" width="32" height="32" />

See [ImageKit Programming Guide](https://developer.apple.com/library/content/documentation/GraphicsImaging/Conceptual/ImageKitProgrammingGuide/IKImagePicker/IKImagePicker.html) for more information.

## Syntax

```
DISPLAY PICTURE TAKER (picture{;options{;OK}})
```

Parameter|Type|Description
------------|------------|----
picture|PICTURE|default picture, picture taken
options|TEXT|options in JSON format; supported attributes are listed below
OK|LONGINT|``1`` if the dialog was validated


* Options

``showEffects`` (boolean)

``showRecentPicture`` (boolean)

``showAddressBookPicture`` (boolean)

``allowsVideoCapture`` (boolean)

``allowsFileChoosing`` (boolean)

``allowsEditing`` (boolean)

``updateRecentPicture`` (boolean)

``informationalText`` (text)

``cropAreaWidth`` (integer)

``cropAreaHeight`` (integer)

``outputImageMaxWidth`` (integer)

``outputImageMaxHeight`` (integer)


### Examples

```
C_PICTURE($picture)
READ PICTURE FILE(Get 4D folder(Current resources folder)+"4D.png";$picture)

C_OBJECT($options)
OB SET($options;"allowsEditing";False;"allowsFileChoosing";False)

DISPLAY PICTURE TAKER ($picture;JSON Stringify($options);$OK)

SET PICTURE TO PASTEBOARD($picture)
```

![2017-06-19 12 21 31](https://user-images.githubusercontent.com/1725068/27268424-52ad2364-54ea-11e7-89f4-b0d8ef3a7658.png)

