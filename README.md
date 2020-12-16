![platform](https://img.shields.io/static/v1?label=platform&message=osx-64&color=blue)
![version](https://img.shields.io/badge/version-17%2B-3E8B93)
[![license](https://img.shields.io/github/license/miyako/4d-plugin-picture-taker)](LICENSE)
![downloads](https://img.shields.io/github/downloads/miyako/4d-plugin-picture-taker/total)

# 4d-plugin-picture-taker

Simple picture taker panel for macOS

4D implementation of [IKPictureTaker](https://developer.apple.com/documentation/quartz/ikpicturetaker?language=objc)

See [ImageKit Programming Guide](https://developer.apple.com/library/content/documentation/GraphicsImaging/Conceptual/ImageKitProgrammingGuide/IKImagePicker/IKImagePicker.html) for more information.

## Syntax

```4d
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
